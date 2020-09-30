/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** StartCallCommand
*/

#ifndef STARTCALLCOMMAND_HPP_
#define STARTCALLCOMMAND_HPP_

#include "ICommand.hpp"
#include "Username.hpp"
#include <cstring>

namespace Babel::Server::Commands
{
    const std::size_t IP_LENGTH = 16;

    class StartCallCommand : public ICommand {
    public:
        StartCallCommand() = default;
        ~StartCallCommand() = default;

        void handle(const unsigned char *, const std::size_t, IUser *) const final;

    private:
#pragma pack(push, 1)
        struct UserCallInfos
        {
            UserCallInfos(const char *username, const char *ip)
            {
                std::strncpy(this->username, username, USERNAME_LENGTH);
                std::strncpy(this->ip, ip, IP_LENGTH);
            }
            char username[USERNAME_LENGTH];
            char ip[IP_LENGTH];
        };

        struct StartCallRequest
        {
            Header header;
        };
#pragma pack(pop)

        void sendInfosToUsers(const std::vector<Username> &, ClassicResponse &) const;
        void sendLoop(const std::vector<IUser *> &, const std::vector<UserCallInfos> &, ClassicResponse &) const;
    };
} // namespace Babel::Server::Commands

#endif /* !STARTCALLCOMMAND_HPP_ */
