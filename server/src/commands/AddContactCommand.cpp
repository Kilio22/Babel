/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AddContactCommand
*/

#include "commands/AddContactCommand.hpp"
#include "SqlDb.hpp"
#include "UserManager.hpp"
#include <boost/asio/streambuf.hpp>

void Babel::Server::Commands::AddContactCommand::handle(const unsigned char *data, const std::shared_ptr<IUser> &user) const
{
    const AddContactRequest *addContactRequest = reinterpret_cast<const AddContactRequest *>(data);
    AddContactsResponse addContactResponse = { { COMMAND_TYPE::ADD_CONTACT }, ADD_CONTACT_RESPONSE_CODE::OK };
    boost::asio::streambuf b;
    std::ostream os(&b);

    if (user == nullptr) {
        return;
    }
    if (!user->isLoggedIn()) {
        addContactResponse.responseCode = ADD_CONTACT_RESPONSE_CODE::NOT_LOGGED_IN;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&addContactResponse), sizeof(AddContactsResponse));
    }
    try {
        SqlDb::getInstance().addContact(user->getUsername(), addContactRequest->username);
        std::vector<Contact> contacts = this->getContacts(user->getUsername());

        os.write(reinterpret_cast<const char *>(&addContactResponse), sizeof(AddContactsResponse));
        os.write(reinterpret_cast<const char *>(contacts.data()), sizeof(Contact) * contacts.size());
        user->getTcpClient()->write(
            boost::asio::buffer_cast<const unsigned char *>(b.data()), sizeof(Contact) * contacts.size() + sizeof(AddContactsResponse));
    } catch (const std::exception &e) {
        addContactResponse.responseCode = ADD_CONTACT_RESPONSE_CODE::OTHER;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&addContactResponse), sizeof(AddContactsResponse));
    }
}

std::vector<Babel::Server::Commands::AddContactCommand::Contact> Babel::Server::Commands::AddContactCommand::getContacts(
    const std::string &username) const
{
    const std::vector<Username> &contactsUsername = SqlDb::getInstance().getUserContacts(username);
    std::vector<Contact> contacts;

    for (const auto &contactUsername : contactsUsername) {
        std::shared_ptr<IUser> user = UserManager::getInstance().getUserByUsername(contactUsername.username);

        if (user == nullptr) {
            contacts.push_back({ contactUsername.username, false });
        } else {
            contacts.push_back({ contactUsername.username, user->isLoggedIn() });
        }
    }
    return contacts;
}