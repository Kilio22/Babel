/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ICommandHandler
*/

#ifndef ICOMMANDHANDLER_HPP_
#define ICOMMANDHANDLER_HPP_

#include <memory>

namespace Babel::Client::Commands
{
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
        USER_IN_CALL,
        NOT_IN_CALL,
        BAD_IP,
        OTHER
    };
    class ICommand {
    public:
        virtual ~ICommand() = default;

        virtual void handle(const unsigned char *, std::size_t) const = 0;
    };
} // namespace Babel::Client::Commands

#endif /* !ICOMMANDHANDLER_HPP_ */
