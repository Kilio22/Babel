/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#include "DisconnectCommand.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include <iostream>

void Babel::Client::Commands::DisconnectCommand::handle(const unsigned char *data, std::size_t bytes) const
{
    const ClassicResponse *disconnectResponse = reinterpret_cast<const ClassicResponse *>(data);

    if (disconnectResponse->responseCode == RESPONSE_CODE::OK) {
        // std::cout << "DISCONNECT - SUCCESS !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->disconnectWorked();
        return;
    }
    if (disconnectResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        // std::cout << "DISCONNECT - USER NOT LOGGED IN !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setError("User not logged in");
        return;
    }
}
