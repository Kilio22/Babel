/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtTcpClient
*/

#include "QtTcpClient.hpp"
#include <iostream>

Babel::Client::Network::QtTcpClient::QtTcpClient(const std::string &ipv4, unsigned short port)
{
    _socket.connectToHost(QString::fromStdString(ipv4), port);
    if (_socket.waitForConnected(5000)) {
        std::cout << "Connected !" << std::endl;
    } else {
        std::cout << _socket.errorString().toStdString() << std::endl;
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