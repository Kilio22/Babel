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
        std::cout << "START CALL - SUCCESS !" << std::endl; // debug
        std::vector<UserCallInfos> users;
        users.assign(reinterpret_cast<const UserCallInfos *>(&data[sizeof(ClassicResponse)]), reinterpret_cast<const UserCallInfos *>(data + bytes));
        for (int i = 0; i < users.size(); i++) {
            std::cout << users.at(i).username << std::endl;
        }
        // TODO : passer fenetre de startCall et appeler le callManager
        return;
    }
    if (startCallResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        std::cout << "START CALL - USER NOT LOGGED IN !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setError("User not logged in");
        return;
    }
    if (startCallResponse->responseCode == RESPONSE_CODE::USER_DISCONNECTED) {
        std::cout << "START CALL - USER YOU ARE CALLING IS DISCONNECTED !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setError("User called not logged in");
        return;
    }
    if (startCallResponse->responseCode == RESPONSE_CODE::OTHER) {
        std::cout << "START CALL - ERROR !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setError("Error");
        return;
    }
}
