/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandFactory
*/

#include "CommandFactory.hpp"
#include "RegisterCommand.hpp"
#include "LoginCommand.hpp"
#include "GetContactsCommand.hpp"
#include "AddContactCommand.hpp"
#include "StartCallCommand.hpp"
#include "StopCallCommand.hpp"
#include "ServiceLocator.hpp"

using namespace Babel::Client::Commands;

const std::unordered_map<enum COMMAND_TYPE, const std::function<ICommand *()>> Babel::Client::CommandFactory::commandMap = {
        {
            COMMAND_TYPE::REGISTER,
            []() { return &ServiceLocator::getInstance().get<RegisterCommand>(); }
        },
        {
            COMMAND_TYPE::LOGIN,
            []() { return &ServiceLocator::getInstance().get<LoginCommand>(); }
        },
        {
            COMMAND_TYPE::GET_CONTACTS,
            []() { return &ServiceLocator::getInstance().get<GetContactsCommand>(); }
        },
        {
            COMMAND_TYPE::ADD_CONTACT,
            []() { return &ServiceLocator::getInstance().get<AddContactCommand>(); }
        },
        {
            COMMAND_TYPE::START_CALL,
            []() { return &ServiceLocator::getInstance().get<StartCallCommand>(); }
        },
        {
            COMMAND_TYPE::STOP_CALL,
            []() { return &ServiceLocator::getInstance().get<StopCallCommand>(); }
        }
    };

Babel::Client::Commands::ICommand *Babel::Client::CommandFactory::createCommandFromCommandType(
    const Babel::Client::Commands::COMMAND_TYPE commandType)
{
    return commandMap.at(commandType)();
}