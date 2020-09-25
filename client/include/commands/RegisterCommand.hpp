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
    signals:
        void registerSuccess();
        void registerWrongUsernameLength();
        void registerWrongPasswordLength();
        void registerUsernameTaken();
        void otherError();

    private:
#pragma pack(push, 1)
        enum class REGISTER_RESPONSE_CODE
        {
            OK,
            WRONG_USERNAME_LENGTH,
            WRONG_PASSWORD_LENGTH,
            USERNAME_TAKEN,
            OTHER
        };
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
} // namespace Babel::Client::Commands

#endif /* !REGISTERCOMMAND_HPP_ */
