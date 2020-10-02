/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** StopCallCommand
*/

#ifndef STOPCALLCOMMAND_HPP_
#define STOPCALLCOMMAND_HPP_

#include "commands/ICommand.hpp"

namespace Babel::Server::Commands
{
    class StopCallCommand : public ICommand {
    public:
        StopCallCommand() = default;
        ~StopCallCommand() override = default;

        void handle(const unsigned char *, std::size_t, IUser *) const final;

    private:
        void stopCalls(const std::vector<std::string> &, ClassicResponse &) const;
    };
} // namespace Babel::Server::Commands

#endif /* !STOPCALLCOMMAND_HPP_ */
