/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** StartCallCommand
*/

#include "commands/StartCallCommand.hpp"
#include "UserManager.hpp"
#include <iostream>
#include <sstream>

void Babel::Server::Commands::StartCallCommand::handle(const unsigned char *data, std::size_t bytesTransfered, IUser *user) const
{
    ClassicResponse classicResponse = { Header(COMMAND_TYPE::START_CALL), RESPONSE_CODE::OK };
    if (!user->isLoggedIn()) {
        classicResponse.responseCode = RESPONSE_CODE::NOT_LOGGED_IN;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }
    if (bytesTransfered - sizeof(StartCallRequest) < sizeof(Username)) {
        classicResponse.responseCode = RESPONSE_CODE::OTHER;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }

    std::vector<Username> usernames;
    usernames.assign(reinterpret_cast<const Username *>(&data[ sizeof(StartCallRequest) ]),
                     reinterpret_cast<const Username *>(data + bytesTransfered));
    usernames.emplace_back(user->getUsername());
    this->sendInfosToUsers(usernames, classicResponse, user);
}

void Babel::Server::Commands::StartCallCommand::sendInfosToUsers(
        const std::vector<Username> &usernames, ClassicResponse &classicResponse, IUser *mainUser) const
{
    std::vector<IUser *> users;
    std::vector<UserCallInfos> usersCallInfos;

    for (const auto &username : usernames) {
        IUser *user = UserManager::getInstance().getUserByUsername(username.username);

        if (user == nullptr) {
            classicResponse.responseCode = RESPONSE_CODE::USER_DISCONNECTED;
            return mainUser->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
        }
        if (user->isInCall()) {
            classicResponse.responseCode = RESPONSE_CODE::USER_IN_CALL;
            return mainUser->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
        }
        users.push_back(user);
        usersCallInfos.emplace_back(user->getUsername().c_str(), user->getTcpClient()->getIp().c_str());
    }
    this->sendLoop(users, usersCallInfos, classicResponse);
}

void Babel::Server::Commands::StartCallCommand::sendLoop(
        const std::vector<IUser *> &users, const std::vector<UserCallInfos> &usersCallInfos, ClassicResponse &classicResponse) const
{
    for (const auto &user : users) {
        std::vector<UserCallInfos> infosToSend;
        std::vector<std::string> calledUsers;
        std::stringbuf b;
        std::ostream os(&b);

        std::copy_if(usersCallInfos.begin(), usersCallInfos.end(), std::back_insert_iterator(infosToSend),
                     [ user ](const UserCallInfos &userCallInfos) { return user->getUsername() != std::string(userCallInfos.username); });
        for (const auto &userCallInfos : usersCallInfos) {
            if (user->getUsername() != userCallInfos.username) {
                calledUsers.emplace_back(userCallInfos.username);
            }
        }
        os.write(reinterpret_cast<const char *>(&classicResponse), sizeof(ClassicResponse));
        os.write(reinterpret_cast<const char *>(infosToSend.data()), infosToSend.size() * sizeof(UserCallInfos));
        user->getTcpClient()->write(
                reinterpret_cast<const unsigned char *>(b.str().c_str()), sizeof(UserCallInfos) * infosToSend.size() + sizeof(ClassicResponse));
        user->setInCall(true);
        user->setCalledUsers(calledUsers);
    }
}
