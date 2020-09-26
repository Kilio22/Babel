/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginCommand
*/

#ifndef LOGINCOMMAND_HPP_
#define LOGINCOMMAND_HPP_

#include "commands/CommandParser.hpp"
#include "commands/ICommand.hpp"

namespace Babel::Server::Commands
{
    class LoginCommand : public ICommand {
    public:
        LoginCommand() = default;
        ~LoginCommand() = default;

        void handle(const unsigned char *, std::size_t, IUser *) const final;

    private:
        enum class LOGIN_RESPONSE_CODE
        {
            OK,
            BAD_COMBINAISON,
            ALREADY_LOGGED,
            OTHER
        };

#pragma pack(push, 1)
        struct LoginRequest
        {
            Header header;
            char username[33];
            char password[43];
        };

        struct LoginResponse
        {
            Header header;
            enum LOGIN_RESPONSE_CODE responseCode;
        };
#pragma pack(pop)
    };
} // namespace Babel::Server::Commands

#endif /* !LOGINCOMMAND_HPP_ */
