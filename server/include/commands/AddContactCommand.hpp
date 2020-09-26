/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AddContactCommand
*/

#ifndef ADDCONTACTCOMMAND_HPP_
#define ADDCONTACTCOMMAND_HPP_

#include "Username.hpp"
#include "commands/CommandParser.hpp"
#include "commands/ICommand.hpp"
#include "network/ITcpClient.hpp"
#include <cstring>

namespace Babel::Server::Commands
{
    class AddContactCommand : public ICommand {
    public:
        AddContactCommand() = default;
        ~AddContactCommand() = default;

        void handle(const unsigned char *, const std::size_t, IUser *) const final;

    private:
        enum class ADD_CONTACT_RESPONSE_CODE
        {
            OK,
            NOT_LOGGED_IN,
            BAD_CONTACT,
            OTHER
        };

#pragma pack(push, 1)
        struct Contact
        {
            Contact(const char *username, bool loggedIn)
                : loggedIn(loggedIn)
            {
                std::strncpy(this->username, username, USERNAME_LENGTH);
            }
            char username[USERNAME_LENGTH];
            bool loggedIn;
        };

        struct AddContactRequest
        {
            Header header;
            char username[USERNAME_LENGTH];
        };

        struct AddContactsResponse
        {
            Header header;
            enum ADD_CONTACT_RESPONSE_CODE responseCode;
        };
#pragma pack(pop)

        std::vector<Contact> getContacts(const std::string &username) const;
    };
}
#endif /* !ADDCONTACTCOMMAND_HPP_ */
