/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AddContactCommand
*/

#include "commands/AddContactCommand.hpp"
#include "UserManager.hpp"
#include "database/SqlDb.hpp"
#include <boost/asio/streambuf.hpp>
#include <iostream>

void Babel::Server::Commands::AddContactCommand::handle(const unsigned char *data, const std::size_t, IUser *user) const
{
    ClassicResponse classicResponse = { { COMMAND_TYPE::ADD_CONTACT }, RESPONSE_CODE::OK };
    if (!user->isLoggedIn()) {
        classicResponse.responseCode = RESPONSE_CODE::NOT_LOGGED_IN;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }

    const AddContactRequest *addContactRequest = reinterpret_cast<const AddContactRequest *>(data);
    if (user->getUsername().compare(addContactRequest->username) == 0) {
        classicResponse.responseCode = RESPONSE_CODE::BAD_CONTACT;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }

    try {
        this->addContact(addContactRequest, classicResponse, user);
        std::vector<Contact> contacts = this->getContacts(user->getUsername());
        this->sendContacts(contacts, classicResponse, user);
    } catch (const std::exception &e) {
        classicResponse.responseCode = RESPONSE_CODE::OTHER;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }
}

void Babel::Server::Commands::AddContactCommand::addContact(
    const AddContactRequest *addContactRequest, ClassicResponse &classicResponse, IUser *user) const
{
    if (SqlDb::getInstance().hasUser(addContactRequest->username) == false) {
        classicResponse.responseCode = RESPONSE_CODE::BAD_CONTACT;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&classicResponse), sizeof(ClassicResponse));
    }
    SqlDb::getInstance().addContact(user->getUsername(), addContactRequest->username);
}

std::vector<Babel::Server::Commands::AddContactCommand::Contact> Babel::Server::Commands::AddContactCommand::getContacts(
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

void Babel::Server::Commands::AddContactCommand::sendContacts(std::vector<Contact> contacts, ClassicResponse &classicResponse, IUser *user) const
{
    boost::asio::streambuf b;
    std::ostream os(&b);

    os.write(reinterpret_cast<const char *>(&classicResponse), sizeof(ClassicResponse));
    os.write(reinterpret_cast<const char *>(contacts.data()), sizeof(Contact) * contacts.size());
    user->getTcpClient()->write(
        boost::asio::buffer_cast<const unsigned char *>(b.data()), (sizeof(Contact) * contacts.size() + sizeof(ClassicResponse)));
}
