/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#include "LoginCommand.hpp"
#include <iostream>

void Babel::Client::Commands::LoginCommand::handle(const unsigned char *data, std::size_t bytes)
{
    const LoginResponse *loginResponse = reinterpret_cast<const struct LoginResponse *>(data);

    if (loginResponse->responseCode == RESPONSE_CODE::OK) {
        std::cout << "LOGIN - LOGIN SUCCESS !" << std::endl; // debug
        emit this->loginSuccess();
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::BAD_COMBINAISON) {
        std::cout << "LOGIN - BAD COMBINAISON !" << std::endl; // debug
        emit this->badLoginCombinaison();
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::ALREADY_LOGGED_IN) {
        std::cout << "LOGIN - USER ALREADY LOGGED IN !" << std::endl; // debug
        emit this->alreadyLoggedIn();
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::OTHER) {
        std::cout << "LOGIN - ERROR !" << std::endl; // debug
        emit this->otherError();
        return;
    }
}

#include "moc_LoginCommand.cpp"