/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** OpenDatabaseException
*/

#include "exceptions/OpenDatabaseException.hpp"

Babel::Server::Exceptions::OpenDatabaseException::OpenDatabaseException(const std::string &message, const std::string &component)
    : BabelServerException(message, component)
{
}
