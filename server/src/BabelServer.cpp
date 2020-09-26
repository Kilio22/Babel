/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AsioTcpServer
*/

#include "BabelServer.hpp"
#include "exceptions/BadArgumentsException.hpp"
#include "network/AsioTcpServer.hpp"
#include <boost/lexical_cast.hpp>
#include <iostream>

Babel::Server::BabelServer::BabelServer(int ac, const char *av[])
{
    if (ac != 2)
        throw Exceptions::BadArgumentsException(
            "Bad args number, got: " + std::to_string(ac) + "but 2 are needed.", "Babel::Server::BabelServer::BabelServer");
    try {
        this->m_port = boost::lexical_cast<unsigned short>(av[1]);
    } catch (const std::exception &e) {
        throw Exceptions::BadArgumentsException(
            "Bad argument, got: \"" + std::string(av[1]) + "\" but a valid port number is needed: " + std::string(e.what()) + ".",
            "Babel::Server::BabelServer::BabelServer");
    }
}

void Babel::Server::BabelServer::run()
{
    std::unique_ptr<ITcpServer> tcpServer = std::make_unique<AsioTcpServer>(this->m_port);

    tcpServer->listen();
}