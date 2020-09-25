/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#include "GetContactsCommand.hpp"
#include <iostream>

void Babel::Client::Commands::GetContactsCommand::handle(const unsigned char *data, std::size_t bytes)
{
    const GetContactsResponse *getContactsResponse = reinterpret_cast<const GetContactsResponse *>(data);

    if (getContactsResponse->responseCode == GET_CONTACTS_RESPONSE_CODE::OK) {
        std::cout << "GET CONTACTS - SUCCESS !" << std::endl; // debug
        std::vector<Contact> contacts;
        contacts.assign(reinterpret_cast<const Contact *>(&data[sizeof(GetContactsResponse)]), reinterpret_cast<const Contact *>(data + bytes));
        emit this->getContacts(contacts);
        return;
    }
    if (getContactsResponse->responseCode == GET_CONTACTS_RESPONSE_CODE::NOT_LOGGED_IN) {
        std::cout << "GET CONTACTS - USER NOT LOGGED IN !" << std::endl; // debug
        emit this->getContactsNotLoggedIn();
        return;
    }
    if (getContactsResponse->responseCode == GET_CONTACTS_RESPONSE_CODE::OTHER) {
        std::cout << "GET CONTACTS - ERROR !" << std::endl; // debug
        emit this->otherError();
        return;
    }
}

#include "moc_GetContactsCommand.cpp"