/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ITcpServer
*/

#ifndef ITCPSERVER_HPP_
#define ITCPSERVER_HPP_

namespace Babel::Server
{
    class ITcpServer {
    public:
        virtual ~ITcpServer() = default;

        virtual void listen() = 0;
    };
} // namespace Babel::Server

#endif /* !ITCPSERVER_HPP_ */
