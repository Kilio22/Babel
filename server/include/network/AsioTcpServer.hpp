/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AsioTcpServer
*/

#ifndef SERVERTCPSOCKET_HPP_
#define SERVERTCPSOCKET_HPP_

#include "network/AsioTcpClient.hpp"
#include "network/ITcpServer.hpp"
#include <boost/asio.hpp>

namespace Babel::Server
{
    class AsioTcpServer : public ITcpServer {
    public:
        AsioTcpServer(unsigned short port);
        ~AsioTcpServer();

        void listen() final;

    private:
        void startAccept();
        void acceptHandler(boost::shared_ptr<AsioTcpClient> asioTcpClient, const boost::system::error_code &error);

    private:
        boost::asio::io_context m_ioContext;
        boost::asio::ip::tcp::acceptor m_acceptor;
    };
} // namespace Babel::Server

#endif /* !SERVERTCPSOCKET_HPP_ */
