/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#ifndef LOGINCOMMAND_HPP_
#define LOGINCOMMAND_HPP_

#include "CommandParser.hpp"
#include "CommandManager.hpp"

namespace Babel::Client::Commands
{
    class LoginCommand : public ICommand {
    public:
        LoginCommand() = default;
        ~LoginCommand() = default;

        void handle(const unsigned char *, std::size_t) final;
    };
} // namespace Babel::Client::Commands

#endif /* !LOGINCOMMAND_HPP_ */
