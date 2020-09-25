/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtUcpClientException
*/

#include "QtUcpClientException.hpp"

Babel::Client::Exceptions::QtUcpClientException::QtUcpClientException(const std::string &message, const std::string &component)
    : ClientException(message, component)
{
}
