/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AddContactCommand
*/

#ifndef ADDCONTACTCOMMAND_HPP_
#define ADDCONTACTCOMMAND_HPP_

#include "Username.hpp"
#include "commands/ICommand.hpp"
#include "network/ITcpClient.hpp"
#include <cstring>

namespace Babel::Server::Commands
{
    class AddContactCommand : public ICommand {
    public:
        AddContactCommand() = default;
        ~AddContactCommand() override = default;

        void handle(const unsigned char *, std::size_t, IUser *) const final;

    private:
#pragma pack(push, 1)
        struct Contact
        {
            Contact(const char *username, bool loggedIn)
                : loggedIn(loggedIn)
            {
                std::strncpy(this->username, username, USERNAME_LENGTH);
            }
            char username[USERNAME_LENGTH]{};
            bool loggedIn;
        };

        struct AddContactRequest
        {
            Header header;
            char username[USERNAME_LENGTH];
        };
#pragma pack(pop)

    private:
        void addContact(const AddContactRequest *, ClassicResponse &, IUser *) const;
        std::vector<Contact> getContacts(const std::string &) const;
        void sendContacts(std::vector<Contact>, ClassicResponse &, IUser *) const;
    };
}
#endif /* !ADDCONTACTCOMMAND_HPP_ */
