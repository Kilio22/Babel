/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandParser
*/

#include "CommandParser.hpp"
#include <iostream>

Babel::Client::CommandParser Babel::Client::CommandParser::commandParserInstance;

Babel::Client::CommandParser &Babel::Client::CommandParser::getInstance()
{
    return commandParserInstance;
}

void Babel::Client::CommandParser::parseCommand(const unsigned char *data, std::size_t bytes_transfered) const
{
    const Commands::Header responseHeader(Commands::COMMAND_TYPE::ERR);
    if (bytes_transfered < sizeof(Commands::Header))
        return;
    const Commands::Header *header = reinterpret_cast<const Commands::Header *>(data);

    if (header->corewarMagic != Commands::corewarMagic)
        return;
    try {
        CommandFactory::createCommandFromCommandType(header->commandType)->handle(data, bytes_transfered);
    } catch (const std::exception &) {
        return;
    }
}