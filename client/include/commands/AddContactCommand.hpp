/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AddContactCommand
*/

#ifndef ADDCONTACTCOMMAND_HPP_
#define ADDCONTACTCOMMAND_HPP_

#include "CommandParser.hpp"
#include "ICommand.hpp"
#include <QtCore/QObject>
#include <cstring>

namespace Babel::Client::Commands
{
    class AddContactCommand : public QObject, public ICommand {
        Q_OBJECT
    public:
        AddContactCommand() = default;
        ~AddContactCommand() = default;

        void handle(const unsigned char *, std::size_t) final;

    private:
#pragma pack(push, 1)
        enum class ADD_CONTACT_RESPONSE_CODE
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

        struct AddContactRequest
        {
            Header header;
            char username[33];
        };

        struct AddContactsResponse
        {
            Header header;
            enum ADD_CONTACT_RESPONSE_CODE responseCode;
        };
#pragma pack(pop)

    signals:
        void addContact(std::vector<Contact> contacts);
        void addContactNotLoggedIn();
        void otherError();
    };
}
#endif /* !ADDCONTACTCOMMAND_HPP_ */
