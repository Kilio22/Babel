/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AddContactCommand
*/

#include "AddContactCommand.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include <iostream>

void Babel::Client::Commands::AddContactCommand::handle(const unsigned char *data, std::size_t bytes)
{
    const AddContactsResponse *addContactResponse = reinterpret_cast<const AddContactsResponse *>(data);

    std::cout << "add contact nb bytes " << bytes << std::endl;
    if (addContactResponse->responseCode == RESPONSE_CODE::OK) {
        std::cout << "ADD CONTACT - SUCCESS !" << std::endl; // debug
        return;
    }
    if (addContactResponse->responseCode == RESPONSE_CODE::BAD_CONTACT) {
        std::cout << "ADD CONTACT - CAN'T ADD YOURSELF !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setError("Invalid contact");
        return;
    }
    if (addContactResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        std::cout << "ADD CONTACT - USER NOT LOGGED IN !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setError("User not logged in");
        return;
    }
    if (addContactResponse->responseCode == RESPONSE_CODE::OTHER) {
        std::cout << "ADD CONTACT - ERROR !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setError("Error");
        return;
    }
}
