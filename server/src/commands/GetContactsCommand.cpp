/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#include "commands/GetContactsCommand.hpp"
#include "UserManager.hpp"
#include "database/SqlDb.hpp"
#include <boost/asio/streambuf.hpp>
#include <iostream>

void Babel::Server::Commands::GetContactsCommand::handle(const unsigned char *, const std::size_t, IUser *user) const
{
    GetContactsResponse getContactsResponse = { Header(COMMAND_TYPE::GET_CONTACTS), RESPONSE_CODE::OK };
    if (!user->isLoggedIn()) {
        getContactsResponse.responseCode = RESPONSE_CODE::NOT_LOGGED_IN;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&getContactsResponse), sizeof(GetContactsResponse));
    }

    try {
        std::vector<Contact> contacts = this->getContacts(user->getUsername());
        boost::asio::streambuf b;
        std::ostream os(&b);

        os.write(reinterpret_cast<const char *>(&getContactsResponse), sizeof(GetContactsResponse));
        os.write(reinterpret_cast<const char *>(contacts.data()), sizeof(Contact) * contacts.size());
        user->getTcpClient()->write(
            boost::asio::buffer_cast<const unsigned char *>(b.data()), (sizeof(Contact) * contacts.size() + sizeof(GetContactsResponse)));
    } catch (const std::exception &e) {
        getContactsResponse.responseCode = RESPONSE_CODE::OTHER;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&getContactsResponse), sizeof(GetContactsResponse));
    }
}

std::vector<Babel::Server::Commands::GetContactsCommand::Contact> Babel::Server::Commands::GetContactsCommand::getContacts(
    const std::string &username) const
{
    const std::vector<Username> &contactsUsername = SqlDb::getInstance().getUserContacts(username);
    std::vector<Contact> contacts;

    for (const auto &contactUsername : contactsUsername) {
        IUser *user = UserManager::getInstance().getUserByUsername(contactUsername.username);

        if (user == nullptr) {
            contacts.push_back({ contactUsername.username, false });
        } else {
            contacts.push_back({ contactUsername.username, user->isLoggedIn() });
        }
    }
    return contacts;
}
