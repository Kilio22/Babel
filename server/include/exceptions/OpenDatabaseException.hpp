/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** OpenDatabaseException
*/

#ifndef OPENDATABASEEXCEPTION_HPP_
#define OPENDATABASEEXCEPTION_HPP_

#include "exceptions/BabelServerException.hpp"

namespace Babel::Server::Exceptions
{
    class OpenDatabaseException : public BabelServerException {
    public:
        OpenDatabaseException(const std::string &message, const std::string &where);
        ~OpenDatabaseException() override = default;
    };
} // namespace Babel::Server

#endif /* !OPENDATABASEEXCEPTION_HPP_ */
