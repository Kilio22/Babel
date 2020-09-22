/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** SignupFailedException
*/

#ifndef SIGNUPFAILEDEXCEPTION_HPP_
#define SIGNUPFAILEDEXCEPTION_HPP_

#include "ClientException.hpp"

namespace Babel::Exceptions
{
    /**
     * @brief Class representing the exception thrown the signup failed (for any reason).
     * 
     */
    class SignupFailedException : public ClientException
    {
        public:
            SignupFailedException(const std::string &component, const std::string &message);
            ~SignupFailedException() = default;
    };
};

#endif /* !SIGNUPFAILEDEXCEPTION_HPP_ */
