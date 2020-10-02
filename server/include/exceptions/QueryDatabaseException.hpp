/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QueryDatabaseException
*/

#ifndef QUERYDATABASEEXCEPTION_HPP_
#define QUERYDATABASEEXCEPTION_HPP_

#include "exceptions/BabelServerException.hpp"

namespace Babel::Server::Exceptions
{
    class QueryDatabaseException : public BabelServerException {
    public:
        QueryDatabaseException(const std::string &message, const std::string &where);
        ~QueryDatabaseException() override = default;

    protected:
    private:
    };
} // namespace Babel::Server::Exceptions

#endif /* !QUERYDATABASEEXCEPTION_HPP_ */
