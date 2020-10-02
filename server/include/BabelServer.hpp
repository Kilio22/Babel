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
        ~BabelServer() override = default;

        void run() final;

    private:
        unsigned short m_port;
    };
}

#endif /* !ASIOSERVER_HPP_ */
