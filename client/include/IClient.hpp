/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IClient
*/

#ifndef ICLIENT_HPP_
#define ICLIENT_HPP_

namespace Babel::Client
{
    class IClient {
        public:
            virtual ~IClient() = default;

            virtual bool connect() = 0;
    };
}

#endif /* !ICLIENT_HPP_ */
