/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#include "commands/RegisterCommand.hpp"
#include "SqlDb.hpp"
#include "exceptions/ConstraintDatabaseException.hpp"
#include <boost/shared_ptr.hpp>
#include <iostream>

void Babel::Server::Commands::RegisterCommand::handle(const unsigned char *data, const std::size_t, IUser *user) const
{
    const RegisterRequest *registerRequest = reinterpret_cast<const struct RegisterRequest *>(data);
    RegisterResponse registerResponse = { Header(COMMAND_TYPE::REGISTER), REGISTER_RESPONSE_CODE::OK };
    const std::string username = registerRequest->username;
    if (username.length() < 3) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::WRONG_USERNAME_LENGTH;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&registerResponse), sizeof(RegisterResponse));
    }

    const std::string password = registerRequest->password;
    if (password.length() < 3) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::WRONG_PASSWORD_LENGTH;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&registerResponse), sizeof(RegisterResponse));
    }

    try {
        SqlDb::getInstance().addUser(username, password);
    } catch (const Exceptions::ConstraintDatabaseException &) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::USERNAME_TAKEN;
    } catch (const std::exception &) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::OTHER;
    }
    return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&registerResponse), sizeof(RegisterResponse));
}
