/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#include "GetContactsCommand.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include <iostream>

void Babel::Client::Commands::GetContactsCommand::handle(const unsigned char *data, std::size_t bytes) const
{
    const GetContactsResponse *getContactsResponse = reinterpret_cast<const GetContactsResponse *>(data);

    if (getContactsResponse->responseCode == RESPONSE_CODE::OK) {
        std::cout << "GET CONTACTS - SUCCESS !" << std::endl; // debug
        std::vector<Contact> contacts;
        std::vector<std::string> contactsNames;
        contacts.assign(reinterpret_cast<const Contact *>(&data[sizeof(GetContactsResponse)]), reinterpret_cast<const Contact *>(data + bytes));
        for (int i = 0; i < contacts.size(); i++) {
            std::cout << contacts.at(i).username << std::endl;
            contactsNames.push_back(contacts.at(i).username);
        }
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setContacts(contactsNames);
        return;
    }
    if (getContactsResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        std::cout << "GET CONTACTS - USER NOT LOGGED IN !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setError("User not logged in");
        return;
    }
    if (getContactsResponse->responseCode == RESPONSE_CODE::OTHER) {
        std::cout << "GET CONTACTS - ERROR !" << std::endl; // debug
        ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setError("Error");
        return;
    }
}
