/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** MissingUsernameException
*/

#include "MissingUsernameException.hpp"

Babel::Client::Exceptions::MissingUsernameException::MissingUsernameException(const std::string &component, const std::string &message)
    : ClientException(component, message)
{
}