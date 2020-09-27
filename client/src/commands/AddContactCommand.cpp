/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AddContactCommand
*/

#include "AddContactCommand.hpp"
#include <iostream>

void Babel::Client::Commands::AddContactCommand::handle(const unsigned char *data, std::size_t bytes)
{
    const AddContactsResponse *addContactResponse = reinterpret_cast<const AddContactsResponse *>(data);

    std::cout << "add contact nb bytes " << bytes << std::endl;
    if (addContactResponse->responseCode == RESPONSE_CODE::OK) {
        std::cout << "ADD CONTACT - SUCCESS !" << std::endl; // debug
        std::vector<Contact> contacts;
        contacts.assign(reinterpret_cast<const Contact *>(&data[sizeof(AddContactsResponse)]), reinterpret_cast<const Contact *>(data + bytes));
        for (int i = 0; i < contacts.size(); i++)
            std::cout << contacts.at(i).username << std::endl;
        emit this->addContact(contacts);
        return;
    }
    if (addContactResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        std::cout << "ADD CONTACT - USER NOT LOGGED IN !" << std::endl; // debug
        emit this->addContactNotLoggedIn();
        return;
    }
    if (addContactResponse->responseCode == RESPONSE_CODE::OTHER) {
        std::cout << "ADD CONTACT - ERROR !" << std::endl; // debug
        emit this->otherError();
        return;
    }
}

#include "moc_AddContactCommand.cpp"