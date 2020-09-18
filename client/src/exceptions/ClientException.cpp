/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ClientException
*/

#include "ClientException.hpp"

Babel::Exceptions::ClientException::ClientException(const std::string &component, const std::string &message)
    : _component(component), _message(message)
{
}

const char *Babel::Exceptions::ClientException::what() const noexcept
{
    return this->_message.c_str();
}

std::string const &Babel::Exceptions::ClientException::getComponent(void) const noexcept
{
    return this->_component;
}