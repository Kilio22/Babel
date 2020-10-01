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
#include <cstring>

namespace Babel::Server::Commands
{
    class GetContactsCommand : public ICommand {
    public:
        GetContactsCommand() = default;
        ~GetContactsCommand() = default;

        void handle(const unsigned char *, const std::size_t, IUser *) const;

    private:
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
#pragma pack(pop)

    private:
        std::vector<Contact> getContacts(const std::string &) const;
        void sendContacts(std::vector<Contact>, ClassicResponse &, IUser *) const;
    };
} // namespace Babel::Server::Commands

#endif /* !GETCONTACTSCOMMAND_HPP_ */
