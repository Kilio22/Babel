/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtTcpClientException
*/

#include "QtTcpClientException.hpp"

Babel::Client::Exceptions::QtTcpClientException::QtTcpClientException(const std::string &message, const std::string &component)
    : BabelClientException(message, component)
{
}