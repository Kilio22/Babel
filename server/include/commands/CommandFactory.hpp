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
#include <map>
#include <memory>

namespace Babel::Server
{
    namespace Commands
    {
        enum COMMAND_TYPE
        {
            REGISTER,
            LOGIN,
            GET_CONTACTS,
            ERR
        };
    } // namespace Commands

    class CommandFactory {
    public:
        CommandFactory();
        ~CommandFactory();

        template <class T>
        static std::unique_ptr<T> createCommand()
        {
            return std::make_unique<T>();
        }

        static std::unique_ptr<Commands::ICommand> createCommandFromCommandType(const enum Babel::Server::Commands::COMMAND_TYPE &commandType);

    private:
        static const std::map<const enum Babel::Server::Commands::COMMAND_TYPE, std::function<std::unique_ptr<Commands::ICommand>()>> commandMap;
    };
} // namespace Babel::Server

#endif /* !FACTORY_HPP_ */
