/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#include "commands/LoginCommand.hpp"
#include "UserManager.hpp"
#include "database/SqlDb.hpp"
#include <iostream>

void Babel::Server::Commands::LoginCommand::handle(const unsigned char *data, const std::size_t, IUser *user) const
{
    LoginCommand::LoginResponse loginResponse = { Header(Commands::COMMAND_TYPE::LOGIN), LOGIN_RESPONSE_CODE::OK };
    if (user->isLoggedIn()) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::ALREADY_LOGGED;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }

    const LoginCommand::LoginRequest *loginRequest = reinterpret_cast<const LoginCommand::LoginRequest *>(data);
    if (loginRequest->password == nullptr || loginRequest->username == nullptr) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::OTHER;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }

    try {
        std::vector<std::string> userLogs = SqlDb::getInstance().getUserLogs(std::string(loginRequest->username));
        if (userLogs.empty()) {
            loginResponse.responseCode = LOGIN_RESPONSE_CODE::BAD_COMBINAISON;
            return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
        }

        if (std::string(loginRequest->password) != std::string(userLogs[1])) {
            loginResponse.responseCode = LOGIN_RESPONSE_CODE::BAD_COMBINAISON;
            return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
        }
        user->setLoggedIn(true);
        user->setUsername(loginRequest->username);
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    } catch (const std::exception &) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::OTHER;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }
}
