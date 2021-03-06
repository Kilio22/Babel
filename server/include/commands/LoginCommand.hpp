/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#ifndef LOGINCOMMAND_HPP_
#define LOGINCOMMAND_HPP_

#include "Username.hpp"
#include "commands/ICommand.hpp"

namespace Babel::Server::Commands
{
    class LoginCommand : public ICommand {
    public:
        LoginCommand() = default;
        ~LoginCommand() override = default;

        void handle(const unsigned char *, std::size_t, IUser *) const final;

    private:
#pragma pack(push, 1)
        struct LoginRequest {
            Header header;
            char username[USERNAME_LENGTH];
            char password[PASSWORD_LENGTH];
            char ip[IP_LENGTH];
        };
#pragma pack(pop)

    private:
        void loginUser(const LoginRequest *, ClassicResponse &, IUser *user) const;
    };
} // namespace Babel::Server::Commands

#endif /* !LOGINCOMMAND_HPP_ */
