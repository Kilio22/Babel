/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BadArgumentsException
*/

#ifndef BADARGUMENTSEXCEPTION_HPP_
#define BADARGUMENTSEXCEPTION_HPP_

#include "BabelClientException.hpp"

namespace Babel::Client::Exceptions
{
    class BadArgumentsException : public BabelClientException {
    public:
        BadArgumentsException(const std::string &message, const std::string &component);
        ~BadArgumentsException() = default;
    };
} // namespace Babel::Client::Exceptions

#endif /* !BADARGUMENTSEXCEPTION_HPP_ */
