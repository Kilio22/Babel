/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ConstraintDatabaseException
*/

#include "exceptions/ConstraintDatabaseException.hpp"

Babel::Server::Exceptions::ConstraintDatabaseException::ConstraintDatabaseException(const std::string &message, const std::string &where)
    : BabelServerException(message, where)
{
}
