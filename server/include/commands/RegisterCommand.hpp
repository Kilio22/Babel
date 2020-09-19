/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#ifndef REGISTERCOMMAND_HPP_
#define REGISTERCOMMAND_HPP_

#include "commands/ICommand.hpp"

namespace Babel::Server::Commands
{
    class RegisterCommand : public ICommand {
    public:
        RegisterCommand() = default;
        ~RegisterCommand() = default;

        void handle() const final;

    protected:
    private:
    };
} // namespace Babel::Server::Commands

#endif /* !REGISTERCOMMAND_HPP_ */
