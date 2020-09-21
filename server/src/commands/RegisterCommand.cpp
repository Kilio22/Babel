/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#include "commands/RegisterCommand.hpp"
#include "SqlDb.hpp"
#include "exceptions/ConstraintDatabaseException.hpp"

void Babel::Server::Commands::RegisterCommand::handle(const unsigned char *data, ITcpClient *tcpClient) const
{
    const RegisterRequest *registerRequest = reinterpret_cast<const struct RegisterRequest *>(data);
    RegisterResponse registerResponse = { Header(COMMAND_TYPE::REGISTER), REGISTER_RESPONSE_CODE::OK };
    const std::string username = registerRequest->username;
    const std::string password = registerRequest->password;

    if (username.length() < 3 || password.length() < 3) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::BAD_COMBINAISON;
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&registerResponse), sizeof(RegisterResponse));
    }
    try {
        SqlDb::getInstance().addUser(username, password);
    } catch (const Exceptions::ConstraintDatabaseException &e) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::USERNAME_TAKEN;
    } catch (const std::exception &e) {
        registerResponse.responseCode = REGISTER_RESPONSE_CODE::OTHER;
    }
    return tcpClient->write(reinterpret_cast<const unsigned char *>(&registerResponse), sizeof(RegisterResponse));
}
