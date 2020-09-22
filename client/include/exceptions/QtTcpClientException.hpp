/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtTcpClientException
*/

#ifndef QTTCPCLIENTEXCEPTION_HPP_
#define QTTCPCLIENTEXCEPTION_HPP_

#include "BabelClientException.hpp"

namespace Babel::Client::Exceptions
{
    class QtTcpClientException : public BabelClientException {
        public:
            QtTcpClientException(const std::string &message, const std::string &component);
            ~QtTcpClientException() = default;
    };
}

#endif /* !QTTCPCLIENTEXCEPTION_HPP_ */