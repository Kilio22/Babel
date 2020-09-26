/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AsioTcpClient
*/

#include "network/AsioTcpClient.hpp"
#include "UserManager.hpp"
#include "commands/CommandParser.hpp"
#include <boost/bind.hpp>
#include <iostream>

Babel::Server::AsioTcpClient::AsioTcpClient(boost::asio::io_context &io_context)
    : m_socket(io_context)
{
}

Babel::Server::AsioTcpClient::~AsioTcpClient()
{
    this->disconnect();
}

boost::asio::ip::tcp::socket &Babel::Server::AsioTcpClient::getSocket()
{
    return this->m_socket;
}

std::string Babel::Server::AsioTcpClient::getIp() const
{
    return this->m_socket.remote_endpoint().address().to_string();
}

void Babel::Server::AsioTcpClient::read()
{
    this->m_socket.async_read_some(boost::asio::buffer(this->m_data, READ_SIZE),
        boost::bind(&AsioTcpClient::handleRead, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Babel::Server::AsioTcpClient::handleRead(const boost::system::error_code &error, std::size_t bytesTransferred)
{
    if (error) {
        this->disconnect();
        return;
    }

    IUser *user = UserManager::getInstance().getUserByTcpClient(this);
    if (user == nullptr) {
        return;
    }

    this->m_bytesTransfered = bytesTransferred;
    user->tcpClientHasData();
    this->read();
}

void Babel::Server::AsioTcpClient::disconnect()
{
    if (this->m_socket.is_open()) {
        std::cout << "disconnected!" << std::endl;
        this->m_socket.close();
    }
    UserManager::getInstance().removeUserByTcpClient(this);
}

void Babel::Server::AsioTcpClient::handleWrite(const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (error) {
        std::cerr << "Something went wrong: " << error.message() << std::endl;
        this->disconnect();
    }
}

void Babel::Server::AsioTcpClient::write(const unsigned char *data, std::size_t size)
{
    this->m_socket.async_write_some(boost::asio::buffer(data, size),
        boost::bind(&AsioTcpClient::handleWrite, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

std::pair<std::size_t, const unsigned char *> Babel::Server::AsioTcpClient::getData() const
{
    return { this->m_bytesTransfered, this->m_data };
}
