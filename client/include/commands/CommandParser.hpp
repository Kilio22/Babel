/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandParser
*/

#ifndef COMMANDPARSER_HPP_
#define COMMANDPARSER_HPP_

#include "CommandFactory.hpp"
#include "ITcpClient.hpp"
#include <memory>

namespace Babel::Client
{
    namespace Commands
    {
        const int corewarMagic = 0xea83f3;

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
    } // namespace Commands

    class CommandParser {
    public:
        ~CommandParser() = default;

        static CommandParser &getInstance();

        void parseCommand(const unsigned char *, size_t bytes_transfered) const;

    private:
        CommandParser() = default;
        CommandParser(const CommandParser &) = delete;
        CommandParser &operator=(const CommandParser &) = delete;

        static CommandParser commandParserInstance;
    };
} // namespace Babel::Client

#endif /* !COMMANDPARSER_HPP_ */
