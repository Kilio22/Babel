/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IServer
*/

#ifndef ISERVER_HPP_
#define ISERVER_HPP_

namespace Babel::Server
{
    class IServer {
    public:
        virtual ~IServer() = default;

        virtual void run() = 0;
    };
} // namespace Babel::Server

#endif /* !ISERVER_HPP_ */
