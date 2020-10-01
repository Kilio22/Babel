/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** DisconnectCommand
*/

#ifndef DISCONNECTCOMMAND_HPP_
#define DISCONNECTCOMMAND_HPP_

#include "commands/ICommand.hpp"
#include <vector>

namespace Babel::Server::Commands
{
    class DisconnectCommand : public ICommand {
    public:
        DisconnectCommand() = default;
        ~DisconnectCommand() = default;

        void handle(const unsigned char *, const std::size_t, IUser *) const;

    private:
        void stopCalls(const std::vector<std::string> &, ClassicResponse &) const;
    };
} // namespace Babel::Server::Commands

#endif /* !DISCONNECTCOMMAND_HPP_ */
