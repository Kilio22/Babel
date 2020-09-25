/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtUcpClientException
*/

#ifndef QTUCPCLIENTEXCEPTION_HPP_
#define QTUCPCLIENTEXCEPTION_HPP_

#include "ClientException.hpp"

namespace Babel::Client::Exceptions
{
    class QtUcpClientException : public ClientException
    {
    public:
        QtUcpClientException(const std::string &message, const std::string &component);
        ~QtUcpClientException() = default;
    };
}

#endif /* !QTUCPCLIENTEXCEPTION_HPP_ */