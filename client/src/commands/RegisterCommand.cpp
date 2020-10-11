/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#include "RegisterCommand.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include <iostream>

void Babel::Client::Commands::RegisterCommand::handle(const unsigned char *data, std::size_t bytes) const
{
    const ClassicResponse *registerResponse = reinterpret_cast<const struct ClassicResponse *>(data);

    (void)bytes;
    if (registerResponse->responseCode == RESPONSE_CODE::OK) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getSignupWindow()->signupWorked();
        return;
    }
    if (registerResponse->responseCode == RESPONSE_CODE::WRONG_USERNAME_LENGTH) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getSignupWindow()->setError("Invalid username lenth");
        return;
    }
    if (registerResponse->responseCode == RESPONSE_CODE::WRONG_PASSWORD_LENGTH) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getSignupWindow()->setError("Invalid password lenth");
        return;
    }
    if (registerResponse->responseCode == RESPONSE_CODE::USERNAME_TAKEN) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getSignupWindow()->setError("Username already taken");
        return;
    }
    if (registerResponse->responseCode == RESPONSE_CODE::OTHER) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getSignupWindow()->setError("Error");
        return;
    }
}
