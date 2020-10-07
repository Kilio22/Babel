/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandParser
*/

#include "commands/CommandParser.hpp"
#include "commands/CommandFactory.hpp"
#include "commands/ICommand.hpp"
#include <iostream>

void Babel::Server::CommandParser::parseCommand(const unsigned char *data, std::size_t bytes_transfered, IUser *user)
{
    const Commands::Header responseHeader(Commands::COMMAND_TYPE::ERR);
    if (bytes_transfered < sizeof(Commands::Header)) {
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    }

    const auto *header = reinterpret_cast<const Commands::Header *>(data);
    if (header->corewarMagic != COREWAR_MAGIC) {
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    }
    try {
        CommandFactory::createCommandFromCommandType(header->commandType)->handle(data, bytes_transfered, user);
    } catch (const std::exception &) {
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    }
}
