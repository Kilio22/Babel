/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#include "StartCallCommand.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include <iostream>

void Babel::Client::Commands::StartCallCommand::handle(const unsigned char *data, std::size_t bytes) const
{
    const ClassicResponse *startCallResponse = reinterpret_cast<const ClassicResponse *>(data);

    if (startCallResponse->responseCode == RESPONSE_CODE::OK) {
        std::vector<UserCallInfos> users;
        users.assign(reinterpret_cast<const UserCallInfos *>(&data[sizeof(ClassicResponse)]), reinterpret_cast<const UserCallInfos *>(data + bytes));
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->callWorked(users);
        return;
    }
    if (startCallResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->setError("User not logged in");
        return;
    }
    if (startCallResponse->responseCode == RESPONSE_CODE::USER_DISCONNECTED) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->setError("User called not logged in");
        return;
    }
    if (startCallResponse->responseCode == RESPONSE_CODE::USER_IN_CALL) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->setError("User called is already in call");
        return;
    }
    if (startCallResponse->responseCode == RESPONSE_CODE::OTHER) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->setError("Error");
        return;
    }
}
