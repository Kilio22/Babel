/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandFactory
*/

#include "commands/CommandFactory.hpp"

const std::map<const enum Babel::Server::Commands::COMMAND_TYPE, std::function<std::unique_ptr<Babel::Server::Commands::ICommand>()>>
    Babel::Server::CommandFactory::commandMap = { { Babel::Server::Commands::COMMAND_TYPE::LOGIN, []() { return nullptr; } } };

std::unique_ptr<Babel::Server::Commands::ICommand> Babel::Server::CommandFactory::createCommandFromCommandType(
    const enum Babel::Server::Commands::COMMAND_TYPE &commandType)
{
    return commandMap.at(commandType)();
}