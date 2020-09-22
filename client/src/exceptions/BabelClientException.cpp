/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelClientException
*/

#include "exceptions/BabelClientException.hpp"

Babel::Client::Exceptions::BabelClientException::BabelClientException(const std::string &message, const std::string &component)
    : message(message)
    , component(component)
{
}

const char *Babel::Client::Exceptions::BabelClientException::what() const noexcept
{
    return this->message.c_str();
}

const char *Babel::Client::Exceptions::BabelClientException::where() const noexcept
{
    return this->component.c_str();
}