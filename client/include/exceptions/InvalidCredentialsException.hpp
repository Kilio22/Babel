/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** InvalidCredentialsException
*/

#ifndef INVALIDCREDENTIALSEXCEPTION_HPP_
#define INVALIDCREDENTIALSEXCEPTION_HPP_

#include "ClientException.hpp"

namespace Babel::Exceptions
{
    /**
     * @brief Class representing the exception thrown when the username / password are incorrect.
     * 
     */
    class InvalidCredentialsException : public ClientException
    {
        public:
            InvalidCredentialsException(const std::string &component, const std::string &message);
            ~InvalidCredentialsException() = default;
    };
};

#endif /* !INVALIDCREDENTIALSEXCEPTION_HPP_ */
