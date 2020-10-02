/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelServerException
*/

#ifndef BABELSERVEREXCEPTION_HPP_
#define BABELSERVEREXCEPTION_HPP_

#include <exception>
#include <string>

namespace Babel::Server::Exceptions
{
    class BabelServerException : public std::exception {
    public:
        BabelServerException(const std::string &message, const std::string &where);
        ~BabelServerException() override = default;

        const char *what() const noexcept final;

        const char *where() const noexcept;

    private:
        std::string m_message;
        std::string m_where;
    };
}

#endif /* !BABELSERVEREXCEPTION_HPP_ */
