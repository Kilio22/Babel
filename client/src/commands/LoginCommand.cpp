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

    (void)bytes;
    if (loginResponse->responseCode == RESPONSE_CODE::OK) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getLoginWindow()->loginWorked();
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::BAD_COMBINAISON) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getLoginWindow()->setError("Invalid username / password");
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::ALREADY_LOGGED_IN) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getLoginWindow()->setError("User already logged in");
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::BAD_IP) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getLoginWindow()->setError("Bad client ip address");
        return;
    }
    if (loginResponse->responseCode == RESPONSE_CODE::OTHER) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getLoginWindow()->setError("Error");
        return;
    }
}
