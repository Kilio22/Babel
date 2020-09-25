/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** StartCallCommand
*/

#ifndef STARTCALLCOMMAND_HPP_
#define STARTCALLCOMMAND_HPP_

#include "CommandParser.hpp"
#include "ICommand.hpp"
#include <cstring>

namespace Babel::Server::Commands
{
    class StartCallCommand : public ICommand {
    public:
        StartCallCommand() = default;
        ~StartCallCommand() = default;

        void handle(const unsigned char *, size_t, const std::shared_ptr<IUser> &) const final;

    private:
#pragma pack(push, 1)
        struct Username
        {
            char username[33];
        };

        struct UserCallInfos
        {
            UserCallInfos(const char *username, const char *ip)
            {
                std::strncpy(this->username, username, 33);
                std::strncpy(this->ip, ip, 13);
            }
            char username[33];
            char ip[13];
        };
        struct StartCallRequest
        {
            Header header;
        };

        enum class START_CALL_RESPONSE_CODE
        {
            OK,
            NOT_LOGGED_IN,
            USER_DISCONNECTED,
            OTHER
        };
        struct StartCallResponse
        {
            Header header;
            enum START_CALL_RESPONSE_CODE responseCode;
        };
#pragma pack(pop)
        void sendInfosToUsers(const std::vector<Username> &, StartCallResponse &) const;
        void sendLoop(const std::vector<std::shared_ptr<IUser>> &, const std::vector<UserCallInfos> &, StartCallResponse &) const;
    };
} // namespace Babel::Server::Commands

#endif /* !STARTCALLCOMMAND_HPP_ */
