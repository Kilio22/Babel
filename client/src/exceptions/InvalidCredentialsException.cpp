/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** InvalidCredentialsException
*/

#include "InvalidCredentialsException.hpp"

Babel::Client::Exceptions::InvalidCredentialsException::InvalidCredentialsException(const std::string &component, const std::string &message)
    : ClientException(component, message)
{
}