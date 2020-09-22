/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** InvalidUsernameException
*/

#ifndef INVALIDUSERNAMEEXCEPTION_HPP_
#define INVALIDUSERNAMEEXCEPTION_HPP_

#include "ClientException.hpp"

namespace Babel::Client::Exceptions
{
    /**
     * @brief Class representing the exception thrown when the Username filled has an invalid format.
     * 
     */
    class InvalidUsernameException : public ClientException
    {
        public:
            InvalidUsernameException(const std::string &component, const std::string &message);
            ~InvalidUsernameException() = default;
    };
};

#endif /* !INVALIDUSERNAMEEXCEPTION_HPP_ */
