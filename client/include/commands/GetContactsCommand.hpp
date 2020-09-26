/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#ifndef GETCONTACTSCOMMAND_HPP_
#define GETCONTACTSCOMMAND_HPP_

#include "CommandParser.hpp"
#include "ICommand.hpp"
#include <cstring>
#include <QtCore/QObject>

namespace Babel::Client::Commands
{
    class GetContactsCommand : public QObject, public ICommand {
        Q_OBJECT
    public:
        GetContactsCommand() = default;
        ~GetContactsCommand() = default;

        void handle(const unsigned char *, std::size_t) final;

    private:
#pragma pack(push, 1)
        enum class GET_CONTACTS_RESPONSE_CODE
        {
            OK,
            NOT_LOGGED_IN,
            OTHER
        };

        struct Contact
        {
            Contact(const char *username, bool loggedIn)
                : loggedIn(loggedIn)
            {
                std::strncpy(this->username, username, 33);
            }
            char username[33];
            bool loggedIn;
        };

        struct GetContactsResponse
        {
            Header header;
            enum GET_CONTACTS_RESPONSE_CODE responseCode;
        };
#pragma pack(pop)

    signals:
        void getContacts(std::vector<Contact> contacts);
        void getContactsNotLoggedIn();
        void otherError();
    };
} // namespace Babel::Client::Commands

#endif /* !GETCONTACTSCOMMAND_HPP_ */
