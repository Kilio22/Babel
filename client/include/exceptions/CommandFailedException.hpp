/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandFailed
*/

#ifndef COMMANDFAILED_HPP_
#define COMMANDFAILED_HPP_

#include "ClientException.hpp"

namespace Babel::Client::Exceptions
{
    /**
     * @brief Class representing the exception thrown the login failed (for any reason).
     * 
     */
    class CommandFailedException : public ClientException
    {
        public:
            CommandFailedException(const std::string &component, const std::string &message);
            ~CommandFailedException() = default;
    };
};

#endif /* !LOGINFAILED_HPP_ */
