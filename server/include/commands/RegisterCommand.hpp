/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#ifndef REGISTERCOMMAND_HPP_
#define REGISTERCOMMAND_HPP_

#include "commands/CommandParser.hpp"
#include "commands/RegisterCommand.hpp"

namespace Babel::Server::Commands
{
    class RegisterCommand : public ICommand {
    public:
        RegisterCommand() = default;
        ~RegisterCommand() = default;

        void handle(const unsigned char *, const std::shared_ptr<IUser> &) const final;

        enum class REGISTER_RESPONSE_CODE
        {
            OK,
            WRONG_USERNAME_LENGTH,
            WRONG_PASSWORD_LENGTH,
            USERNAME_TAKEN,
            OTHER
        };

#pragma pack(push, 1)
        struct RegisterRequest
        {
            Header header;
            char username[33];
            char password[43];
        };
        struct RegisterResponse
        {
            Header header;
            enum REGISTER_RESPONSE_CODE responseCode;
        };
#pragma pack(pop)
    };
} // namespace Babel::Server::Commands

#endif /* !REGISTERCOMMAND_HPP_ */
