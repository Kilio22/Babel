/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AsioTcpServer
*/

#ifndef SERVERTCPSOCKET_HPP_
#define SERVERTCPSOCKET_HPP_

#include "AsioTcpClient.hpp"
#include <boost/asio.hpp>

namespace Babel::Server
{
    class AsioTcpServer {
    public:
        AsioTcpServer(unsigned short port);
        ~AsioTcpServer();

        void listen();

    private:
        void startAccept();
        void acceptHandler(boost::shared_ptr<AsioTcpClient> asioTcpClient, const boost::system::error_code &error);

        boost::asio::io_context io_context;
        boost::asio::ip::tcp::acceptor acceptor;
    };
} // namespace Babel::Server

#endif /* !SERVERTCPSOCKET_HPP_ */
