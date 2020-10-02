/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#ifndef REGISTERCOMMAND_HPP_
#define REGISTERCOMMAND_HPP_

#include "Username.hpp"
#include "commands/ICommand.hpp"

namespace Babel::Server::Commands
{
    class RegisterCommand : public ICommand {
    public:
        RegisterCommand() = default;
        ~RegisterCommand() override = default;

        void handle(const unsigned char *, std::size_t, IUser *) const final;

    private:
#pragma pack(push, 1)
        struct RegisterRequest {
            Header header;
            char username[USERNAME_LENGTH];
            char password[PASSWORD_LENGTH];
        };
#pragma pack(pop)
    };
} // namespace Babel::Server::Commands

#endif /* !REGISTERCOMMAND_HPP_ */
