/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ConstraintDatabaseException
*/

#ifndef CONSTRAINTDATABASEEXCEPTION_HPP_
#define CONSTRAINTDATABASEEXCEPTION_HPP_

#include "exceptions/BabelServerException.hpp"

namespace Babel::Server::Exceptions
{
    class ConstraintDatabaseException : public BabelServerException {
    public:
        ConstraintDatabaseException(const std::string &message, const std::string &where);
        ~ConstraintDatabaseException() override = default;

    protected:
    private:
    };
} // namespace Babel::Server::Exceptions

#endif /* !CONSTRAINTDATABASEEXCEPTION_HPP_ */
