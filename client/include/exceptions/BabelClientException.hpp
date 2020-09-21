/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelClientException
*/

#ifndef BABELCLIENTEXCEPTION_HPP_
#define BABELCLIENTEXCEPTION_HPP_

#include <exception>
#include <string>

namespace Babel::Client::Exceptions
{
    class BabelClientException : public std::exception {
    public:
        BabelClientException(const std::string &message, const std::string &component);
        virtual ~BabelClientException() = default;

        const char *what() const noexcept final;

        const char *where() const noexcept;

    private:
        std::string message;
        std::string component;
    };
}

#endif /* !BABELCLIENTEXCEPTION_HPP_ */
