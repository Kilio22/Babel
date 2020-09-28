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

void Babel::Client::Commands::GetContactsCommand::handle(const unsigned char *data, std::size_t bytes)
{
    const GetContactsResponse *getContactsResponse = reinterpret_cast<const GetContactsResponse *>(data);

    if (getContactsResponse->responseCode == RESPONSE_CODE::OK) {
        std::cout << "GET CONTACTS - SUCCESS !" << std::endl; // debug
        std::vector<Contact> contacts;
        contacts.assign(reinterpret_cast<const Contact *>(&data[sizeof(GetContactsResponse)]), reinterpret_cast<const Contact *>(data + bytes));
        for (int i = 0; i < contacts.size(); i++)
            std::cout << contacts.at(i).username << std::endl;
        return;
    }
    if (getContactsResponse->responseCode == RESPONSE_CODE::NOT_LOGGED_IN) {
        std::cout << "GET CONTACTS - USER NOT LOGGED IN !" << std::endl; // debug
        return;
    }
    if (getContactsResponse->responseCode == RESPONSE_CODE::OTHER) {
        std::cout << "GET CONTACTS - ERROR !" << std::endl; // debug
        return;
    }
}
