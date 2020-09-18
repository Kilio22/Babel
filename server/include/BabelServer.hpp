/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AsioTcpServer
*/

#ifndef ASIOSERVER_HPP_
#define ASIOSERVER_HPP_

#include "IServer.hpp"
#include <memory>

namespace Babel::Server
{
    class BabelServer : public IServer {
    public:
        BabelServer(int ac, const char *av[]);
        ~BabelServer() = default;

        void run() final;

    private:
        unsigned short port;
    };
}

#endif /* !ASIOSERVER_HPP_ */
