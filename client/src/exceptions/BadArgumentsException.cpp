/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BadArgumentsException
*/

#include "BadArgumentsException.hpp"

Babel::Client::Exceptions::BadArgumentsException::BadArgumentsException(const std::string &message, const std::string &component)
    : ClientException(message, component)
{
}
