/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandFactory
*/

#include "commands/CommandFactory.hpp"
#include "commands/LoginCommand.hpp"
#include "commands/RegisterCommand.hpp"

using namespace Babel::Server::Commands;

const std::map<const enum COMMAND_TYPE, std::function<std::unique_ptr<ICommand>()>> Babel::Server::CommandFactory::commandMap
    = { { COMMAND_TYPE::REGISTER, []() { return CommandFactory::createCommand<RegisterCommand>(); } },
          { COMMAND_TYPE::LOGIN, []() { return CommandFactory::createCommand<LoginCommand>(); } } };

std::unique_ptr<Babel::Server::Commands::ICommand> Babel::Server::CommandFactory::createCommandFromCommandType(
    const enum Babel::Server::Commands::COMMAND_TYPE &commandType)
{
    return commandMap.at(commandType)();
}