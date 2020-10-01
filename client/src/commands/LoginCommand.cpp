/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#include "LoginCommand.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include <iostream>

void Babel::Client::Commands::LoginCommand::handle(const unsigned char *data, std::size_t bytes) const
{
    const ClassicResponse *loginResponse = reinterpret_cast<const struct ClassicResponse *>(data);

    if (loginResponse->responseCode == RESPONSE_CODE::OK) {
        std::cout << "LOGIN - LOGIN SUCCESS !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getLoginWindow()->loginWorked();
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::BAD_COMBINAISON) {
        std::cout << "LOGIN - BAD COMBINAISON !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getLoginWindow()->setError("Invalid username / password");
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::ALREADY_LOGGED_IN) {
        std::cout << "LOGIN - USER ALREADY LOGGED IN !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getLoginWindow()->setError("User already logged in");
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::BAD_IP) {
        std::cout << "LOGIN - BAD IP ADDRESS !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getLoginWindow()->setError("Bad client ip address");
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::OTHER) {
        std::cout << "LOGIN - ERROR !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getLoginWindow()->setError("Error");
        return;
    }
}
