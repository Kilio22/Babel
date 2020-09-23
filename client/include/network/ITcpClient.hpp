/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ITcpClient
*/

#ifndef ITCPCLIENT_HPP_
#define ITCPCLIENT_HPP_

#include <string>

namespace Babel::Client::Network
{
    class ITcpClient
    {
        public:
            virtual ~ITcpClient() = default;

            virtual bool send(const unsigned char *data) = 0;
    };
}

#endif /* !ITCPCLIENT_HPP_ */