/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#include "commands/LoginCommand.hpp"
#include "SqlDb.hpp"
#include "UserManager.hpp"

void Babel::Server::Commands::LoginCommand::handle(const unsigned char *data, ITcpClient *tcpClient) const
{
    const LoginCommand::LoginRequest *loginRequest = reinterpret_cast<const LoginCommand::LoginRequest *>(data);
    LoginCommand::LoginResponse loginResponse = { Header(Commands::COMMAND_TYPE::LOGIN), LOGIN_RESPONSE_CODE::OK };
    std::vector<std::string> userLogs;
    std::shared_ptr<Babel::Server::IUser> user = UserManager::getInstance().getUserByTcpClient(tcpClient);

    if (user == nullptr)
        return;
    if (user->isLoggedIn()) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::ALREADY_LOGGED;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }
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
    if (userLogs.empty()) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::BAD_COMBINAISON;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }
    if (std::string(loginRequest->password) == std::string(userLogs[1])) {
        loginResponse.responseCode = LOGIN_RESPONSE_CODE::BAD_COMBINAISON;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
    }
    user->setLoggedIn(true);
    return tcpClient->write(reinterpret_cast<const unsigned char *>(&loginResponse), sizeof(LoginCommand::LoginResponse));
}
