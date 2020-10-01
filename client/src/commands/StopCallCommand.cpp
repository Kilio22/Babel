/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** StopCallCommand
*/

#include "StopCallCommand.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include <iostream>

void Babel::Client::Commands::StopCallCommand::handle(const unsigned char *data, std::size_t bytes) const
{
    const ClassicResponse *stopCallResponse = reinterpret_cast<const struct ClassicResponse *>(data);

    if (stopCallResponse->responseCode == RESPONSE_CODE::OK) {
        std::cout << "STOP CALL - SUCCESS !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getCallWindow()->EndCallWorked();
        return;
    }
    if (stopCallResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        std::cout << "STOP CALL - USER NOT LOGGED IN !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getCallWindow()->setError("User not logged in");
        return;
    }
    if (stopCallResponse->responseCode == RESPONSE_CODE::NOT_IN_CALL) {
        std::cout << "STOP CALL - USER NOT IN CALL !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getCallWindow()->setError("User not in call");
        return;
    }
}
