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
#include <unordered_map>
#include <memory>

namespace Babel::Client
{
    namespace Commands
    {
        enum COMMAND_TYPE
        {
            REGISTER,
            LOGIN,
            GET_CONTACTS,
            ADD_CONTACT,
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

        static Commands::ICommand *createCommandFromCommandType(const Babel::Client::Commands::COMMAND_TYPE &commandType);

    private:
        static const std::unordered_map<const Babel::Client::Commands::COMMAND_TYPE, std::function<Commands::ICommand *()>> commandMap;
    };
} // namespace Babel::Client

#endif /* !FACTORY_HPP_ */
