/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtTcpClient
*/

#include "QtTcpClient.hpp"
#include "QtTcpClientException.hpp"
#include <iostream>

Babel::Client::Network::QtTcpClient::QtTcpClient(const std::string &ipv4, unsigned short port)
{
    _socket.connectToHost(QString::fromStdString(ipv4), port);
    if (!_socket.waitForConnected(3000)) {
        throw Babel::Client::Exceptions::QtTcpClientException(
            "Can't connect to server: " + _socket.errorString().toStdString(), "Babel::Client::Network::QtTcpClient::QtTcpClient");
    }
}

Babel::Client::Network::QtTcpClient::~QtTcpClient()
{
}

void Babel::Client::Network::QtTcpClient::send(const std::string &data)
{
    return;
}

std::string Babel::Client::Network::QtTcpClient::receive()
{
    return "";
}