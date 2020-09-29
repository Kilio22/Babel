/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** StartCallCommand
*/

#ifndef STARTCALLCOMMAND_HPP_
#define STARTCALLCOMMAND_HPP_

#include "CommandParser.hpp"
#include "CommandManager.hpp"
#include "ICommand.hpp"
#include <cstring>

namespace Babel::Client::Commands
{
    class StartCallCommand : public ICommand {
    public:
        StartCallCommand() = default;
        ~StartCallCommand() = default;

        void handle(const unsigned char *, std::size_t) const final;
    };
} // namespace Babel::Client::Commands

#endif /* !STARTCALLCOMMAND_HPP_ */
