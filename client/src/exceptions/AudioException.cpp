/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioException
*/

#include "exceptions/AudioException.hpp"

Babel::Exceptions::AudioException::AudioException(const std::string &what)
    : std::runtime_error(what)
    , _what(what)
{
}

const char *Babel::Exceptions::AudioException::what() const noexcept
{
    return this->_what.c_str();
}
