/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#include "commands/RegisterCommand.hpp"
#include "database/SqlDb.hpp"
#include "exceptions/ConstraintDatabaseException.hpp"
#include <boost/shared_ptr.hpp>
#include <iostream>

void Babel::Server::Commands::RegisterCommand::handle(const unsigned char *data, const std::size_t, IUser *user) const
{
    const RegisterRequest *registerRequest = reinterpret_cast<const struct RegisterRequest *>(data);
    ClassicResponse classicResponse = { Header(COMMAND_TYPE::REGISTER), RESPONSE_CODE::OK };
    const std::string username = registerRequest->username;
    if (username.length() < 3) {
        classicResponse.responseCode = RESPONSE_CODE::WRONG_USERNAME_LENGTH;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }

    const std::string password = registerRequest->password;
    if (password.length() < 3) {
        classicResponse.responseCode = RESPONSE_CODE::WRONG_PASSWORD_LENGTH;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }

    try {
        SqlDb::getInstance().addUser(username, password);
    } catch (const Exceptions::ConstraintDatabaseException &) {
        classicResponse.responseCode = RESPONSE_CODE::USERNAME_TAKEN;
    } catch (const std::exception &) {
        classicResponse.responseCode = RESPONSE_CODE::OTHER;
    }
    return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
}
