/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** MissingPasswordException
*/

#include "MissingPasswordException.hpp"

Babel::Client::Exceptions::MissingPasswordException::MissingPasswordException(const std::string &component, const std::string &message)
    : ClientException(component, message)
{
}