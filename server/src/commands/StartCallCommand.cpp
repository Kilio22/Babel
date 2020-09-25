/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** StartCallCommand
*/

#include "commands/StartCallCommand.hpp"
#include "UserManager.hpp"
#include <boost/asio/streambuf.hpp>

void Babel::Server::Commands::StartCallCommand::handle(const unsigned char *data, size_t bytesTransfered, const std::shared_ptr<IUser> &user) const
{
    StartCallResponse startCallResponse = { Header(COMMAND_TYPE::START_CALL), START_CALL_RESPONSE_CODE::OK };
    std::vector<Username> usernames;

    if (!user->isLoggedIn()) {
        startCallResponse.responseCode = START_CALL_RESPONSE_CODE::NOT_LOGGED_IN;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&startCallResponse), sizeof(StartCallResponse));
    }
    if (bytesTransfered - sizeof(StartCallRequest) < sizeof(Username)) {
        startCallResponse.responseCode = START_CALL_RESPONSE_CODE::OTHER;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&startCallResponse), sizeof(StartCallResponse));
    }
    usernames.assign(reinterpret_cast<const Username *>(&data[sizeof(StartCallRequest)]), reinterpret_cast<const Username *>(data + bytesTransfered));
    this->sendInfosToUsers(usernames, startCallResponse);
}

void Babel::Server::Commands::StartCallCommand::sendInfosToUsers(const std::vector<Username> &usernames, StartCallResponse &startCallResponse) const
{
    std::vector<std::shared_ptr<IUser>> users;
    std::vector<UserCallInfos> usersCallInfos;

    for (const auto &username : usernames) {
        std::shared_ptr<IUser> user = UserManager::getInstance().getUserByUsername(username.username);

        if (user == nullptr) {
            startCallResponse.responseCode = START_CALL_RESPONSE_CODE::USER_DISCONNECTED;
            return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&startCallResponse), sizeof(StartCallResponse));
        }
        users.push_back(user);
        usersCallInfos.push_back({ user->getUsername().c_str(), user->getTcpClient()->getIp().c_str() });
    }
    this->sendLoop(users, usersCallInfos, startCallResponse);
}

void Babel::Server::Commands::StartCallCommand::sendLoop(
    const std::vector<std::shared_ptr<IUser>> &users, const std::vector<UserCallInfos> &usersCallInfos, StartCallResponse &startCallResponse) const
{
    for (const auto &user : users) {
        std::vector<UserCallInfos> infosToSend;
        boost::asio::streambuf b;
        std::ostream os(&b);

        std::copy_if(usersCallInfos.begin(), usersCallInfos.end(), std::back_insert_iterator(infosToSend),
            [user](const UserCallInfos &userCallInfos) { return user->getUsername().compare(std::string(userCallInfos.username)) != 0; });
        os.write(reinterpret_cast<const char *>(&startCallResponse), sizeof(StartCallResponse));
        os.write(reinterpret_cast<const char *>(infosToSend.data()), infosToSend.size() * sizeof(UserCallInfos));
        user->getTcpClient()->write(
            boost::asio::buffer_cast<const unsigned char *>(b.data()), sizeof(UserCallInfos) * infosToSend.size() + sizeof(StartCallResponse));
    }
}
