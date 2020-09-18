/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** MissingPasswordException
*/

#ifndef MISSINGPASSWORDEXCEPTION_HPP_
#define MISSINGPASSWORDEXCEPTION_HPP_

#include "ClientException.hpp"

namespace Babel::Exceptions
{
    /**
     * @brief Class representing the exception thrown when the user doesn't fill in the Password Text Box in the Sign In / Login window.
     * 
     */
    class MissingPasswordException : public ClientException
    {
    public:
        MissingPasswordException(const std::string &component, const std::string &message);
        ~MissingPasswordException() = default;
    };
}

#endif /* !MISSINGPASSWORDEXCEPTION_HPP_ */
