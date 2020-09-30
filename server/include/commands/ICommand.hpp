/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ICommandHandler
*/

#ifndef ICOMMANDHANDLER_HPP
#define ICOMMANDHANDLER_HPP

#include "IUser.hpp"

namespace Babel::Server::Commands
{
    const std::size_t PASSWORD_LENGTH = 43;

    enum COMMAND_TYPE
    {
        REGISTER,
        LOGIN,
        GET_CONTACTS,
        ADD_CONTACT,
        START_CALL,
        STOP_CALL,
        DISCONNECT,
        ERR
    };

    enum RESPONSE_CODE
    {
        OK,
        NOT_LOGGED_IN,
        ALREADY_LOGGED_IN,
        BAD_CONTACT,
        BAD_COMBINAISON,
        WRONG_USERNAME_LENGTH,
        WRONG_PASSWORD_LENGTH,
        USERNAME_TAKEN,
        USER_DISCONNECTED,
        NOT_IN_CALL,
        OTHER
    };

#pragma pack(push, 1)

    struct Header
    {
        Header(enum COMMAND_TYPE commandType)
            : corewarMagic(0xea83f3)
            , commandType(commandType)
        {
        }
        int corewarMagic;
        enum COMMAND_TYPE commandType;
    };
    struct ClassicResponse
    {
        Header header;
        enum RESPONSE_CODE responseCode;
    };
#pragma pack(pop)

    class ICommand {
    public:
        virtual ~ICommand() = default;

        virtual void handle(const unsigned char *, const std::size_t, IUser *) const = 0;
    };
} // namespace Babel::Server::Commands

#endif /* !ICOMMANDHANDLER_HPP_ */
