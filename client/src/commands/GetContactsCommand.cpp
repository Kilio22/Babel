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
    const ClassicResponse *getContactsResponse = reinterpret_cast<const ClassicResponse *>(data);

    if (getContactsResponse->responseCode == RESPONSE_CODE::OK) {
        std::vector<Contact> contacts;
        std::vector<std::string> contactsNames;
        contacts.assign(reinterpret_cast<const Contact *>(&data[sizeof(ClassicResponse)]), reinterpret_cast<const Contact *>(data + bytes));
        for (std::size_t i = 0; i < contacts.size(); i++)
            contactsNames.push_back(contacts.at(i).username);
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->setContacts(contacts);
        return;
    }
    if (getContactsResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->setError("User not logged in");
        return;
    }
    if (getContactsResponse->responseCode == RESPONSE_CODE::OTHER) {
        ServiceLocator::getInstance().get<Gui::WindowManager>().getMainWindow()->setError("Error");
        return;
    }
}
