/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandParser
*/

#include "commands/CommandParser.hpp"

Babel::Server::CommandParser Babel::Server::CommandParser::commandParserInstance;

Babel::Server::CommandParser &Babel::Server::CommandParser::getInstance()
{
    return commandParserInstance;
}

void Babel::Server::CommandParser::parseCommand(unsigned char *data, Babel::Server::ITcpClient *tcpClient) { }