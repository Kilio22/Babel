/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioException
*/

#include "exceptions/AudioException.hpp"

Babel::Client::Exceptions::AudioException::AudioException(const std::string &what)
    : std::runtime_error(what)
    , _what(what)
{
}

const char *Babel::Client::Exceptions::AudioException::what() const noexcept
{
    return this->_what.c_str();
}
