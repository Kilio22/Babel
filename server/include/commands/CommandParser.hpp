/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandParser
*/

#ifndef COMMANDPARSER_HPP_
#define COMMANDPARSER_HPP_

#include "IUser.hpp"
#include "network/ITcpClient.hpp"
#include <memory>

namespace Babel::Server
{
    const int COREWAR_MAGIC = 0xea83f3;

    class CommandParser {
    public:
        ~CommandParser() = default;

        static CommandParser &getInstance();

        void parseCommand(const unsigned char *, std::size_t, IUser *) const;

    private:
        CommandParser() = default;
        CommandParser(const CommandParser &) = delete;
        CommandParser &operator=(const CommandParser &) = delete;

    private:
        static CommandParser commandParserInstance;
    };
} // namespace Babel::Server

#endif /* !COMMANDPARSER_HPP_ */
