/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** DisconnectCommand
*/

#include "commands/DisconnectCommand.hpp"
#include "UserManager.hpp"

void Babel::Server::Commands::DisconnectCommand::handle(const unsigned char *, std::size_t, IUser *user) const
{
    ClassicResponse classicResponse = { { COMMAND_TYPE::DISCONNECT }, RESPONSE_CODE::OK };
    if (!user->isLoggedIn()) {
        classicResponse.responseCode = RESPONSE_CODE::NOT_LOGGED_IN;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }
    if (!user->isInCall()) {
        user->setUsername("");
        user->setLoggedIn(false);
        user->getTcpClient()->setIp("");
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }

    const std::vector<std::string> &calledUsernames = user->getCalledUsers();
    classicResponse.header.commandType = COMMAND_TYPE::STOP_CALL;
    this->stopCalls(calledUsernames, classicResponse);

    user->setInCall(false);
    user->setCalledUsers({});
    user->setUsername("");
    user->setLoggedIn(false);
    user->getTcpClient()->setIp("");
    classicResponse.header.commandType = COMMAND_TYPE::DISCONNECT;
    return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
}

void Babel::Server::Commands::DisconnectCommand::stopCalls(const std::vector<std::string> &calledUsernames, ClassicResponse &classicResponse) const
{
    for (const auto &calledUsername : calledUsernames) {
        IUser *calledUser = UserManager::getInstance().getUserByUsername(calledUsername);

        if (calledUser == nullptr) {
            continue;
        }
        calledUser->setInCall(false);
        calledUser->setCalledUsers({});
        calledUser->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }
}
