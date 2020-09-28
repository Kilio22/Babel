/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#ifndef REGISTERCOMMAND_HPP_
#define REGISTERCOMMAND_HPP_

#include "CommandParser.hpp"
#include "CommandManager.hpp"
#include "ICommand.hpp"

namespace Babel::Client::Commands
{
    class RegisterCommand : public ICommand {
    public:
        RegisterCommand() = default;
        ~RegisterCommand() = default;

        void handle(const unsigned char *, std::size_t) final;
    };
} // namespace Babel::Client::Commands

#endif /* !REGISTERCOMMAND_HPP_ */
