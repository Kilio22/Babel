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

    (void)bytes;
    if (disconnectResponse->responseCode == RESPONSE_CODE::OK) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->disconnectWorked();
        return;
    }
    if (disconnectResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->setError("User not logged in");
        return;
    }
}
