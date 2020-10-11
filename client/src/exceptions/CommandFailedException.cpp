/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandFailedException
*/

#include "CommandFailedException.hpp"

Babel::Client::Exceptions::CommandFailedException::CommandFailedException(const std::string &component, const std::string &message)
    : ClientException(component, message)
{
}