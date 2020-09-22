/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QueryDatabaseException
*/

#include "exceptions/QueryDatabaseException.hpp"

Babel::Server::Exceptions::QueryDatabaseException::QueryDatabaseException(const std::string &message, const std::string &component)
    : BabelServerException(message, component)
{
}
