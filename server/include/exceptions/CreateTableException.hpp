/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CreateTableException
*/

#ifndef CREATETABLEEXCEPTION_HPP_
#define CREATETABLEEXCEPTION_HPP_

#include "exceptions/BabelServerException.hpp"

namespace Babel::Server::Exceptions
{
    class CreateTableException : public BabelServerException {
    public:
        CreateTableException(const std::string &message, const std::string &where);
        ~CreateTableException() = default;
    };
} // namespace Babel::Server

#endif /* !CREATETABLEEXCEPTION_HPP_ */
