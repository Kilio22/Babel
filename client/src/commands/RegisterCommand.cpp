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

    if (registerResponse->responseCode == RESPONSE_CODE::OK) {
        std::cout << "REGISTER - REGISTER SUCCESS !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getSignupWindow()->signupWorked("JeanNeymar");
        return;
    }
    if (registerResponse->responseCode == RESPONSE_CODE::WRONG_USERNAME_LENGTH) {
        std::cout << "REGISTER - WRONG USERNAME LENGTH !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getSignupWindow()->setError("Invalid username lenth");
        return;
    }
    if (registerResponse->responseCode == RESPONSE_CODE::WRONG_PASSWORD_LENGTH) {
        std::cout << "REGISTER - WRONG PASSWORD LENGTH !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getSignupWindow()->setError("Invalid password lenth");
        return;
    }
    if (registerResponse->responseCode == RESPONSE_CODE::USERNAME_TAKEN) {
        std::cout << "REGISTER - USERNAME TAKEN !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getSignupWindow()->setError("Username already taken");
        return;
    }
    if (registerResponse->responseCode == RESPONSE_CODE::OTHER) {
        std::cout << "REGISTER - ERROR !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getSignupWindow()->setError("Error");
        return;
    }
}
