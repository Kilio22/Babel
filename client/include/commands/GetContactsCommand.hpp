/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#ifndef GETCONTACTSCOMMAND_HPP_
#define GETCONTACTSCOMMAND_HPP_

#include "CommandParser.hpp"
#include "CommandManager.hpp"
#include "ICommand.hpp"
#include <cstring>

namespace Babel::Client::Commands
{
    class GetContactsCommand : public ICommand {
    public:
        GetContactsCommand() = default;
        ~GetContactsCommand() = default;

        void handle(const unsigned char *, std::size_t) const final;
    };
} // namespace Babel::Client::Commands

#endif /* !GETCONTACTSCOMMAND_HPP_ */
