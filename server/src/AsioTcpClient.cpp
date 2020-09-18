/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AsioTcpClient
*/

#include "AsioTcpClient.hpp"
#include <boost/bind.hpp>
#include <iostream>

Babel::Server::AsioTcpClient::AsioTcpClient(boost::asio::io_context &io_context)
    : socket(io_context)
{
}

Babel::Server::AsioTcpClient::~AsioTcpClient()
{
    this->disconnect();
}

boost::asio::ip::tcp::socket &Babel::Server::AsioTcpClient::getSocket()
{
    return this->socket;
}

void Babel::Server::AsioTcpClient::read()
{
    this->socket.async_read_some(boost::asio::buffer(this->data, readSize),
        boost::bind(&AsioTcpClient::handleRead, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Babel::Server::AsioTcpClient::handleRead(const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (error) {
        this->disconnect();
        return;
    }
    this->read();
}

void Babel::Server::AsioTcpClient::disconnect()
{
    if (this->socket.is_open()) {
        std::cout << "disconnected!" << std::endl;
        this->socket.close();
    }
}

void Babel::Server::AsioTcpClient::write() { }