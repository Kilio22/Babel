/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AsioTcpServer
*/

#include "AsioTcpServer.hpp"
#include "AsioTcpClient.hpp"
#include "User.hpp"
#include "UsersManager.hpp"
#include <boost/bind.hpp>
#include <boost/make_shared.hpp>
#include <iostream>

Babel::Server::AsioTcpServer::AsioTcpServer(unsigned short port)
    : io_context()
    , acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
    this->startAccept();
}

Babel::Server::AsioTcpServer::~AsioTcpServer() { }

void Babel::Server::AsioTcpServer::listen()
{
    this->io_context.run();
}

void Babel::Server::AsioTcpServer::startAccept()
{
    boost::shared_ptr<AsioTcpClient> newConnection = boost::make_shared<AsioTcpClient>(this->io_context);

    this->acceptor.async_accept(
        newConnection->getSocket(), boost::bind(&AsioTcpServer::acceptHandler, this, newConnection, boost::asio::placeholders::error));
}

void Babel::Server::AsioTcpServer::acceptHandler(boost::shared_ptr<AsioTcpClient> asioTcpClient, const boost::system::error_code &error)
{
    if (error) {
        std::cerr << "Something went wrong: " << error.message() << std::endl;
        asioTcpClient->disconnect();
    } else {
        std::cout << "New client!" << std::endl;
        asioTcpClient->read();
        UsersManager::getInstance().addUser(std::make_shared<User>(asioTcpClient));
    }
    this->startAccept();
}
