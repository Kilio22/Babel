/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ClientException
*/

#ifndef CLIENTEXCEPTION_HPP_
#define CLIENTEXCEPTION_HPP_

#include <exception>
#include <string>

#define __ERROR_STR(f, l, fu) (#f " at line " #l "(" #fu ")")
#define _ERROR_STR(f, l, fu) __ERROR_STR(f, l, fu)
#define ERROR_STR _ERROR_STR(__FILE__, __LINE__, __func__)

namespace Babel::Client::Exceptions
{
    /**
     * @brief Class representing all client-side exceptions
     * 
     */
    class ClientException : public std::exception
    {
        public:
            ClientException(const std::string &component, const std::string &message);
            virtual ~ClientException() = default;

            /**
             * @brief Returns a C-style character string describing the general cause of the current error.
             * @return const char* The string
             */
            const char *what() const noexcept final;

            /**
             * @brief Gets the component where the exception has been thrown
             * @return const std::string& The component's name
             */
            const std::string &getComponent(void) const noexcept;

        private:
            std::string _component;
            std::string _message;
    };
};

#endif /* !CLIENTEXCEPTION_HPP_ */