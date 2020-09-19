/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ICommandHandler
*/

#ifndef ICOMMANDHANDLER_HPP_
#define ICOMMANDHANDLER_HPP_

namespace Babel::Server::Commands
{
    class ICommand {
    public:
        virtual ~ICommand() = default;

        virtual void handle() const = 0;
    };
} // namespace Babel::Server::Commands

#endif /* !ICOMMANDHANDLER_HPP_ */
