/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BadArgumentsException
*/

#ifndef BADARGUMENTSEXCEPTION_HPP_
#define BADARGUMENTSEXCEPTION_HPP_

#include "exceptions/BabelServerException.hpp"

namespace Babel::Server::Exceptions
{
    class BadArgumentsException : public BabelServerException {
    public:
        BadArgumentsException(const std::string &message, const std::string &where);
        ~BadArgumentsException() = default;
    };
} // namespace Babel::Server::Exceptions

#endif /* !BADARGUMENTSEXCEPTION_HPP_ */
