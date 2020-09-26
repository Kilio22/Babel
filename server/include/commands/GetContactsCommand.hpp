/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#ifndef GETCONTACTSCOMMAND_HPP_
#define GETCONTACTSCOMMAND_HPP_

#include "ICommand.hpp"
#include "Username.hpp"
#include "commands/CommandParser.hpp"
#include <cstring>

namespace Babel::Server::Commands
{
    class GetContactsCommand : public ICommand {
    public:
        GetContactsCommand() = default;
        ~GetContactsCommand() = default;

        void handle(const unsigned char *, const std::size_t, IUser *) const;

    private:
        enum class GET_CONTACTS_RESPONSE_CODE
        {
            OK,
            NOT_LOGGED_IN,
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

        struct GetContactsResponse
        {
            Header header;
            enum GET_CONTACTS_RESPONSE_CODE responseCode;
        };
#pragma pack(pop)

        std::vector<Contact> getContacts(const std::string &) const;
    };
} // namespace Babel::Server::Commands

#endif /* !GETCONTACTSCOMMAND_HPP_ */
