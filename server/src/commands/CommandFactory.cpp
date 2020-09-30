/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandFactory
*/

#include "commands/CommandFactory.hpp"
#include "commands/AddContactCommand.hpp"
#include "commands/DisconnectCommand.hpp"
#include "commands/GetContactsCommand.hpp"
#include "commands/LoginCommand.hpp"
#include "commands/RegisterCommand.hpp"
#include "commands/StartCallCommand.hpp"
#include "commands/StopCallCommand.hpp"

using namespace Babel::Server::Commands;

const std::unordered_map<enum COMMAND_TYPE, const std::function<ICommand *()>> Babel::Server::CommandFactory::m_commandMap
    = { { COMMAND_TYPE::REGISTER, []() { return &CommandFactory::createCommand<RegisterCommand>(); } },
          { COMMAND_TYPE::LOGIN, []() { return &CommandFactory::createCommand<LoginCommand>(); } },
          { COMMAND_TYPE::ADD_CONTACT, []() { return &CommandFactory::createCommand<AddContactCommand>(); } },
          { COMMAND_TYPE::GET_CONTACTS, []() { return &CommandFactory::createCommand<GetContactsCommand>(); } },
          { COMMAND_TYPE::START_CALL, []() { return &CommandFactory::createCommand<StartCallCommand>(); } },
          { COMMAND_TYPE::STOP_CALL, []() { return &CommandFactory::createCommand<StopCallCommand>(); } },
          { COMMAND_TYPE::DISCONNECT, []() { return &CommandFactory::createCommand<DisconnectCommand>(); } } };

Babel::Server::Commands::ICommand *Babel::Server::CommandFactory::createCommandFromCommandType(const enum COMMAND_TYPE commandType)
{
    return m_commandMap.at(commandType)();
}