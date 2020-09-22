/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#include "commands/LoginCommand.hpp"
#include "SqlDb.hpp"

void Babel::Server::Commands::LoginCommand::handle(const unsigned char *data, ITcpClient *tcpClient) const
{
    const LoginCommand::LoginRequest *loginRequest = reinterpret_cast<const LoginCommand::LoginRequest *>(data);
    LoginCommand::LoginResponse loginResponse = { Header(Commands::COMMAND_TYPE::LOGIN), LOGIN_RESPONSE_CODE::OK };
    const char **userLogs = nullptr;

    if (loginRequest->password == nullptr || loginRequest->username == nullptr) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::OTHER;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }
    try {
        userLogs = SqlDb::getInstance().getUserLogs(std::string(loginRequest->username));
    } catch (const std::exception &e) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::OTHER;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }
    if (userLogs == nullptr) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::BAD_COMBINAISON;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }
    if (std::string(loginRequest->password).compare(std::string(userLogs[1])) != 0) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::BAD_COMBINAISON;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }
    return tcpClient->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
}
