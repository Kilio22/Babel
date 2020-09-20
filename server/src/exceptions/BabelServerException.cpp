/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelServerException
*/

#include "exceptions/BabelServerException.hpp"

Babel::Server::Exceptions::BabelServerException::BabelServerException(const std::string &message, const std::string &component)
    : message(message)
    , component(component)
{
}

const char *Babel::Server::Exceptions::BabelServerException::what() const noexcept
{
    return this->message.c_str();
}

const char *Babel::Server::Exceptions::BabelServerException::where() const noexcept
{
    return this->component.c_str();
}