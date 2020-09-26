/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandFactory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "ICommand.hpp"
#include <functional>
#include <memory>
#include <unordered_map>

namespace Babel::Server
{
    namespace Commands
    {
        enum COMMAND_TYPE
        {
            REGISTER,
            LOGIN,
            GET_CONTACTS,
            ADD_CONTACT,
            START_CALL,
            STOP_CALL,
            ERR
        };
    } // namespace Commands

    class CommandFactory {
    public:
        CommandFactory();
        ~CommandFactory();

        template <class T>
        static T &createCommand()
        {
            static T instance;

            return instance;
        }

        static Commands::ICommand *createCommandFromCommandType(const enum Babel::Server::Commands::COMMAND_TYPE commandType);

    private:
        static const std::unordered_map<enum Babel::Server::Commands::COMMAND_TYPE, const std::function<Commands::ICommand *()>> m_commandMap;
    };
} // namespace Babel::Server

#endif /* !FACTORY_HPP_ */