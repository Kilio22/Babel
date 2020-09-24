/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#include "LoginCommand.hpp"
#include <iostream>

void Babel::Client::Commands::LoginCommand::handle(const unsigned char *data) const
{
    const LoginResponse *loginResponse = reinterpret_cast<const struct LoginResponse *>(data);

    // std::cout << "LOGIN ANSWER - Username : " << loginRequest->username << " && password : " << loginRequest->password << std::endl; // debug
    // if (user == nullptr)
    //     return;
    // if (user->isLoggedIn()) {
    //     loginResponse.responseCode = LOGIN_RESPONSE_CODE::ALREADY_LOGGED;
    //     return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    // }
    // if (loginRequest->password == nullptr || loginRequest->username == nullptr) {
    //     loginResponse.responseCode = LOGIN_RESPONSE_CODE::OTHER;
    //     return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    // }
    // try {
    //     userLogs = SqlDb::getInstance().getUserLogs(std::string(loginRequest->username));
    // } catch (const std::exception &) {
    //     loginResponse.responseCode = LOGIN_RESPONSE_CODE::OTHER;
    //     return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    // }
    // if (userLogs.empty()) {
    //     loginResponse.responseCode = LOGIN_RESPONSE_CODE::BAD_COMBINAISON;
    //     return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    // }
    // if (std::string(loginRequest->password) != std::string(userLogs[1])) {
    //     loginResponse.responseCode = LOGIN_RESPONSE_CODE::BAD_COMBINAISON;
    //     return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    // }
    // user->setLoggedIn(true);
    // user->setUsername(loginRequest->username);
    // std::cout << "LOGIN SUCCESS" << std::endl; // debug
    // return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
}
