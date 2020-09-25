/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandFactory
*/

#include "commands/CommandFactory.hpp"
#include "commands/AddContactCommand.hpp"
#include "commands/GetContactsCommand.hpp"
#include "commands/LoginCommand.hpp"
#include "commands/RegisterCommand.hpp"

using namespace Babel::Server::Commands;

const std::unordered_map<const enum COMMAND_TYPE, std::function<ICommand *()>> Babel::Server::CommandFactory::commandMap
    = { { COMMAND_TYPE::REGISTER, []() { return &CommandFactory::createCommand<RegisterCommand>(); } },
          { COMMAND_TYPE::LOGIN, []() { return &CommandFactory::createCommand<LoginCommand>(); } },
          { COMMAND_TYPE::ADD_CONTACT, []() { return &CommandFactory::createCommand<AddContactCommand>(); } },
          { COMMAND_TYPE::GET_CONTACTS, []() { return &CommandFactory::createCommand<GetContactsCommand>(); } } };

Babel::Server::Commands::ICommand *Babel::Server::CommandFactory::createCommandFromCommandType(
    const enum Babel::Server::Commands::COMMAND_TYPE &commandType)
{
    return commandMap.at(commandType)();
}