/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** Commands
*/

#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_

namespace Babel::Client::Commands
{
    const int corewarMagic = 0xea83f3;

    enum COMMAND_TYPE
    {
        REGISTER,
        LOGIN,
        ERR
    };

    enum class LOGIN_RESPONSE_CODE
    {
        OK,
        BAD_COMBINAISON,
        OTHER
    };

    enum class REGISTER_RESPONSE_CODE
    {
        OK,
        WRONG_USERNAME_LENGTH,
        WRONG_PASSWORD_LENGTH,
        USERNAME_TAKEN,
        OTHER
    };

#pragma pack(push, 1) // to remove padding to avoid problem with different compilers and with network transfer.

    struct Header
    {
        Header(enum COMMAND_TYPE commandType)
            : corewarMagic(0xea83f3)
            , commandType(commandType)
        {
        }
        int corewarMagic;
        enum COMMAND_TYPE commandType;
    };

#pragma pack(pop)

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
}

#endif /* !COMMANDS_HPP_ */
