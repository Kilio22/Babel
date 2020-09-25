/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#include "RegisterCommand.hpp"
#include <iostream>

void Babel::Client::Commands::RegisterCommand::handle(const unsigned char *data, std::size_t bytes)
{
    const RegisterResponse *registerResponse = reinterpret_cast<const struct RegisterResponse *>(data);

    if (registerResponse->responseCode == REGISTER_RESPONSE_CODE::OK) {
        std::cout << "REGISTER - REGISTER SUCCESS !" << std::endl; // debug
        emit this->registerSuccess();
        return;
    }
    if (registerResponse->responseCode == REGISTER_RESPONSE_CODE::WRONG_USERNAME_LENGTH) {
        std::cout << "REGISTER - WRONG USERNAME LENGTH !" << std::endl; // debug
        emit this->registerWrongUsernameLength();
        return;
    }
    if (registerResponse->responseCode == REGISTER_RESPONSE_CODE::WRONG_PASSWORD_LENGTH) {
        std::cout << "REGISTER - WRONG PASSWORD LENGTH !" << std::endl; // debug
        emit this->registerWrongPasswordLength();
        return;
    }
    if (registerResponse->responseCode == REGISTER_RESPONSE_CODE::USERNAME_TAKEN) {
        std::cout << "REGISTER - USERNAME TAKEN !" << std::endl; // debug
        emit this->registerUsernameTaken();
        return;
    }
    if (registerResponse->responseCode == REGISTER_RESPONSE_CODE::OTHER) {
        std::cout << "REGISTER - ERROR !" << std::endl; // debug
        emit this->otherError();
        return;
    }
}

#include "moc_RegisterCommand.cpp"