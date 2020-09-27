/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** StopCallCommand
*/

#ifndef STOPCALLCOMMAND_HPP_
#define STOPCALLCOMMAND_HPP_

#include "commands/CommandParser.hpp"
#include "commands/ICommand.hpp"

namespace Babel::Server::Commands
{
    class StopCallCommand : public ICommand {
    public:
        StopCallCommand() = default;
        ~StopCallCommand() = default;

        void handle(const unsigned char *, const std::size_t, IUser *) const final;

    private:
#pragma pack(push, 1)
        struct StopCallRequest
        {
            Header header;
        };

        struct StopCallResponse
        {
            Header header;
            enum RESPONSE_CODE responseCode;
        };
#pragma pack(pop)
    };
} // namespace Babel::Server::Commands

#endif /* !STOPCALLCOMMAND_HPP_ */
