/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AsioTcpClient
*/

#ifndef CLIENTTCPSOCKET_HPP_
#define CLIENTTCPSOCKET_HPP_

#include "ITcpClient.hpp"
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <deque>

namespace Babel::Server
{
    const int readSize = 4096;

    class AsioTcpClient : public boost::enable_shared_from_this<AsioTcpClient>, public ITcpClient {
    public:
        AsioTcpClient(boost::asio::io_context &io_context);
        virtual ~AsioTcpClient();

        boost::asio::ip::tcp::socket &getSocket();

        std::string getIp() const final;
        void read() final;
        void write(const unsigned char *data, size_t size) final;
        void disconnect() final;
        std::pair<size_t, const unsigned char *> getData() const final;

    private:
        void handleRead(const boost::system::error_code &error, std::size_t bytes_transferred);
        void handleWrite(const boost::system::error_code &error, std::size_t bytes_transferred);

        boost::asio::ip::tcp::socket socket;
        unsigned char data[readSize];
        size_t bytesTransfered;
    };
} // namespace Babel::Server

#endif /* !CLIENTTCPSOCKET_HPP_ */
