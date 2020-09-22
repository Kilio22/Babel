/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** SignupFailedException
*/

#include "SignupFailedException.hpp"

Babel::Exceptions::SignupFailedException::SignupFailedException(const std::string &component, const std::string &message)
    : ClientException(component, message)
{
}