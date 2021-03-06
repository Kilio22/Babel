/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AddContactCommand
*/

#ifndef ADDCONTACTCOMMAND_HPP_
#define ADDCONTACTCOMMAND_HPP_

#include "CommandManager.hpp"
#include "CommandParser.hpp"
#include "ICommand.hpp"
#include <cstring>

namespace Babel::Client::Commands
{
    class AddContactCommand : public ICommand {
    public:
        AddContactCommand() = default;
        ~AddContactCommand() = default;

        void handle(const unsigned char *, std::size_t) const final;
    };
}
#endif /* !ADDCONTACTCOMMAND_HPP_ */
