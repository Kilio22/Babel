/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginFailedException
*/

#include "LoginFailedException.hpp"

Babel::Exceptions::LoginFailedException::LoginFailedException(const std::string &component, const std::string &message)
    : ClientException(component, message)
{
}