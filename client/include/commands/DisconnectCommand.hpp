/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** DisconnectCommand
*/

#ifndef DISCONNECTCOMMAND_HPP_
#define DISCONNECTCOMMAND_HPP_

#include "CommandManager.hpp"
#include "CommandParser.hpp"
#include "ICommand.hpp"

namespace Babel::Client::Commands
{
    class DisconnectCommand : public ICommand {
    public:
        DisconnectCommand() = default;
        ~DisconnectCommand() = default;

        void handle(const unsigned char *, std::size_t) const;
    };
} // namespace Babel::Client::Commands

#endif /* !DISCONNECTCOMMAND_HPP_ */
