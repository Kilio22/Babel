/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginFailed
*/

#ifndef LOGINFAILED_HPP_
#define LOGINFAILED_HPP_

#include "ClientException.hpp"

namespace Babel::Exceptions
{
    /**
     * @brief Class representing the exception thrown the login failed (for any reason).
     * 
     */
    class LoginFailedException : public ClientException
    {
    public:
        LoginFailedException(const std::string &component, const std::string &message);
        ~LoginFailedException() = default;
    };
}

#endif /* !LOGINFAILED_HPP_ */
