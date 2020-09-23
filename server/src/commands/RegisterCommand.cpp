/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#include "commands/RegisterCommand.hpp"
#include "SqlDb.hpp"
#include "exceptions/ConstraintDatabaseException.hpp"
#include <iostream>

void Babel::Server::Commands::RegisterCommand::handle(const unsigned char *data, ITcpClient *tcpClient) const
{
    const RegisterRequest *registerRequest = reinterpret_cast<const struct RegisterRequest *>(data);
    RegisterResponse registerResponse = { Header(COMMAND_TYPE::REGISTER), REGISTER_RESPONSE_CODE::OK };
    const std::string username = registerRequest->username;
    const std::string password = registerRequest->password;

    std::cout << "REGISTER - Username : " << username << " && password : " << password << std::endl; //debug
    if (username.length() < 3) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::WRONG_USERNAME_LENGTH;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&registerResponse), sizeof(RegisterResponse));
    }
    if (password.length() < 3) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::WRONG_PASSWORD_LENGTH;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&registerResponse), sizeof(RegisterResponse));
    }
    try {
        SqlDb::getInstance().addUser(username, password);
    } catch (const Exceptions::ConstraintDatabaseException &) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::USERNAME_TAKEN;
    } catch (const std::exception &) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::OTHER;
    }
    std::cout << "REGISTER SUCCESS" << std::endl; //debug
    return tcpClient->write(reinterpret_cast<const unsigned char *>(&registerResponse), sizeof(RegisterResponse));
}
