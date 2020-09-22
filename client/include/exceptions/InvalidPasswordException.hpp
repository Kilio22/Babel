/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** InvalidPasswordException
*/

#ifndef INVALIDPASSWORDEXCEPTION_HPP_
#define INVALIDPASSWORDEXCEPTION_HPP_

#include "ClientException.hpp"

namespace Babel::Exceptions
{
    /**
     * @brief Class representing the exception thrown when the Password filled has an invalid format.
     * 
     */
    class InvalidPasswordException : public ClientException
    {
        public:
            InvalidPasswordException(const std::string &component, const std::string &message);
            ~InvalidPasswordException() = default;
    };
};

#endif /* !INVALIDPASSWORDEXCEPTION_HPP_ */