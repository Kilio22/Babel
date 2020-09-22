/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** InvalidPasswordException
*/

#include "InvalidPasswordException.hpp"

Babel::Client::Exceptions::InvalidPasswordException::InvalidPasswordException(const std::string &component, const std::string &message)
    : ClientException(component, message)
{
}