/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ITcpClient
*/

#ifndef ITCPCLIENT_HPP_
#define ITCPCLIENT_HPP_

#include <string>

namespace Babel::Server
{
    class ITcpClient {
    public:
        virtual ~ITcpClient() = default;

        virtual void read() = 0;
        virtual void write(const unsigned char *data, std::size_t size) = 0;
        virtual void disconnect() = 0;
        virtual std::string getIp() const = 0;
        virtual std::pair<std::size_t, const unsigned char *> getData() const = 0;
    };
} // namespace Babel::Server

#endif /* !ITCPCLIENT_HPP_ */
