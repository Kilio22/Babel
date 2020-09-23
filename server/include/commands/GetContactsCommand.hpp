/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#ifndef GETCONTACTSCOMMAND_HPP_
#define GETCONTACTSCOMMAND_HPP_

#include "ICommand.hpp"
#include "commands/CommandParser.hpp"

namespace Babel::Server::Commands
{
    class GetContactsCommand : public ICommand {
    public:
        GetContactsCommand() = default;
        ~GetContactsCommand() = default;

        void handle(const unsigned char *data, ITcpClient *tcpClient) const;

#pragma pack(push, 1)
        enum class GET_CONTACTS_RESPONSE_CODE
        {
            OK,
            NOT_LOGGED_IN,
            OTHER
        };

        struct GetContactsResponse
        {
            Header header;
            enum GET_CONTACTS_RESPONSE_CODE responseCode;
            char *contacts;
        };
#pragma pack(pop)
    };
} // namespace Babel::Server::Commands

#endif /* !GETCONTACTSCOMMAND_HPP_ */

