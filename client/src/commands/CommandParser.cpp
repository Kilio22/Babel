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

void Babel::Client::CommandParser::parseCommand(const unsigned char *data, size_t bytes_transfered) const
{
    std::cout << "Parsing de la réponse serveur" << std::endl;
    // const Commands::Header responseHeader(Commands::COMMAND_TYPE::ERR);
    // std::cout << bytes_transfered << " bytes !" << std::endl; // debug
    // if (bytes_transfered < sizeof(Commands::Header)) {
    //     return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    // }
    // const Commands::Header *header = reinterpret_cast<const Commands::Header *>(data);

    // std::cout << "received something, header : " << header->commandType << std::endl;
    // if (header->corewarMagic != Commands::corewarMagic) {
    //     return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    // }
    // try {
    //     CommandFactory::createCommandFromCommandType(header->commandType)->handle(data, user);
    // } catch (const std::exception &) {
    //     return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&responseHeader), sizeof(Commands::Header));
    // }
}