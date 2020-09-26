/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AsioTcpClient
*/

#include "AsioTcpClient.hpp"
#include "UserManager.hpp"
#include "commands/CommandParser.hpp"
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

std::string Babel::Server::AsioTcpClient::getIp() const
{
    return this->socket.remote_endpoint().address().to_string();
}

void Babel::Server::AsioTcpClient::read()
{
    this->socket.async_read_some(boost::asio::buffer(this->data, readSize),
        boost::bind(&AsioTcpClient::handleRead, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Babel::Server::AsioTcpClient::handleRead(const boost::system::error_code &error, std::size_t bytesTransferred)
{
    if (error) {
        this->disconnect();
        return;
    }
    std::shared_ptr<IUser> user = UserManager::getInstance().getUserByTcpClient(this);
    if (user == nullptr) {
        return;
    }
    this->bytesTransfered = bytesTransferred;
    user->tcpClientHasData();
    this->read();
}

void Babel::Server::AsioTcpClient::disconnect()
{
    if (this->socket.is_open()) {
        std::cout << "disconnected!" << std::endl;
        this->socket.close();
        UserManager::getInstance().removeUserByTcpClient(this);
    }
}

void Babel::Server::AsioTcpClient::handleWrite(const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (error) {
        std::cerr << "Something went wrong: " << error.message() << std::endl;
        this->disconnect();
    }
}

void Babel::Server::AsioTcpClient::write(const unsigned char *data, size_t size)
{
    this->socket.async_write_some(boost::asio::buffer(data, size),
        boost::bind(&AsioTcpClient::handleWrite, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

std::pair<size_t, const unsigned char *> Babel::Server::AsioTcpClient::getData() const
{
    return { this->bytesTransfered, this->data };
}
