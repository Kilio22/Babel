/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** InvalidUsernameException
*/

#include "InvalidUsernameException.hpp"

Babel::Client::Exceptions::InvalidUsernameException::InvalidUsernameException(const std::string &component, const std::string &message)
    : ClientException(component, message)
{
}