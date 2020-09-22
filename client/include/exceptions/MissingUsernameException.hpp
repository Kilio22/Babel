/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** MissingUsernameException
*/

#ifndef MISSINGUSERNAMEEXCEPTION_HPP_
#define MISSINGUSERNAMEEXCEPTION_HPP_

#include "ClientException.hpp"

namespace Babel::Client::Exceptions
{
    /**
     * @brief Class representing the exception thrown when the user doesn't fill in the Username Text Box in the Sign In / Login window.
     * 
     */
    class MissingUsernameException : public ClientException
    {
        public:
            MissingUsernameException(const std::string &component, const std::string &message);
            ~MissingUsernameException() = default;
    };
};

#endif /* !MISSINGUSERNAMEEXCEPTION_HPP_ */
