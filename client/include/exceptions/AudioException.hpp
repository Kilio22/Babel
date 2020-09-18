/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioException
*/

#ifndef AUDIOEXCEPTION_HPP_
#define AUDIOEXCEPTION_HPP_

#include <stdexcept>

namespace Babel::Exceptions
{
    class AudioException : public std::runtime_error
    {
    public:
        AudioException(const std::string &what);
        ~AudioException() = default;

        const char *what(void) const noexcept override;

    private:
        std::string _what;
    };
}

#endif /* !AUDIOEXCEPTION_HPP_ */
