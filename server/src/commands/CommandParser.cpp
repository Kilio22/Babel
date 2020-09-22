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

void Babel::Server::CommandParser::parseCommand(const unsigned char *data, size_t bytes_transfered, Babel::Server::ITcpClient *tcpClient) const
{
    const Commands::Header responseHeader(Commands::COMMAND_TYPE::ERROR);
    if (bytes_transfered < sizeof(Commands::Header)) {
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    }
    const Commands::Header *header = reinterpret_cast<const Commands::Header *>(data);

    std::cout << "received something, header : " << header->commandType << std::endl;
    if (header->corewarMagic != Commands::corewarMagic) {
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    }
    try {
        CommandFactory::createCommandFromCommandType(header->commandType)->handle(data, tcpClient);
    } catch (const std::exception &) {
        return tcpClient->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    }
}