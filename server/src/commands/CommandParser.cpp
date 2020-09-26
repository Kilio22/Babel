/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandParser
*/

#include "commands/CommandParser.hpp"
#include <iostream>

Babel::Server::CommandParser Babel::Server::CommandParser::commandParserInstance;

Babel::Server::CommandParser &Babel::Server::CommandParser::getInstance()
{
    return commandParserInstance;
}

void Babel::Server::CommandParser::parseCommand(const unsigned char *data, size_t bytes_transfered, const std::shared_ptr<IUser> &user) const
{
    const Commands::Header responseHeader(Commands::COMMAND_TYPE::ERR);
    if (bytes_transfered < sizeof(Commands::Header)) {
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    }

    const Commands::Header *header = reinterpret_cast<const Commands::Header *>(data);
    if (header->corewarMagic != Commands::corewarMagic) {
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    }
    try {
        CommandFactory::createCommandFromCommandType(header->commandType)->handle(data, bytes_transfered, user);
    } catch (const std::exception &) {
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    }
}