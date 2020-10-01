/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#include "commands/LoginCommand.hpp"
#include "UserManager.hpp"
#include "database/DatabaseProvider.hpp"
#include "database/SqlDb.hpp"
#include <iostream>

void Babel::Server::Commands::LoginCommand::handle(const unsigned char *data, const std::size_t, IUser *user) const
{
    ClassicResponse classicResponse = { Header(Commands::COMMAND_TYPE::LOGIN), RESPONSE_CODE::OK };
    if (user->isLoggedIn()) {
        classicResponse.responseCode = RESPONSE_CODE::ALREADY_LOGGED_IN;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }

    const LoginCommand::LoginRequest *loginRequest = reinterpret_cast<const LoginRequest *>(data);
    if (loginRequest->password == nullptr || loginRequest->username == nullptr) {
        classicResponse.responseCode = RESPONSE_CODE::OTHER;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }
    if (user->getTcpClient()->setIp(loginRequest->ip) == false) {
        classicResponse.responseCode = RESPONSE_CODE::BAD_IP;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }

    try {
        this->loginUser(loginRequest, classicResponse, user);
    } catch (const std::exception &) {
        classicResponse.responseCode = RESPONSE_CODE::OTHER;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }
}

void Babel::Server::Commands::LoginCommand::loginUser(const LoginRequest *loginRequest, ClassicResponse &classicResponse, IUser *user) const
{
    std::vector<std::string> userLogs = DatabaseProvider::getDb<SqlDb>()->getUserLogs(loginRequest->username);
    if (userLogs.empty()) {
        classicResponse.responseCode = RESPONSE_CODE::BAD_COMBINAISON;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }
    if (std::string(loginRequest->password) != std::string(userLogs[1])) {
        classicResponse.responseCode = RESPONSE_CODE::BAD_COMBINAISON;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }

    user->setLoggedIn(true);
    user->setUsername(loginRequest->username);
    user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
}

bool Babel::Server::Commands::LoginCommand::checkIp(const std::string &ip) const { }
