/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** RegisterCommand
*/

#ifndef REGISTERCOMMAND_HPP_
#define REGISTERCOMMAND_HPP_

#include "CommandParser.hpp"
#include "ICommand.hpp"
#include <QtCore/QObject>

namespace Babel::Client::Commands
{
    class RegisterCommand : public QObject, public ICommand {
        Q_OBJECT
    public:
        RegisterCommand() = default;
        ~RegisterCommand() = default;

        void handle(const unsigned char *, std::size_t) final;

    private:
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
            enum RESPONSE_CODE responseCode;
        };
#pragma pack(pop)

    signals:
        void registerSuccess();
        void registerWrongUsernameLength();
        void registerWrongPasswordLength();
        void registerUsernameTaken();
        void otherError();
    };
} // namespace Babel::Client::Commands

#endif /* !REGISTERCOMMAND_HPP_ */
