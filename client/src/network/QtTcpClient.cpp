/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtTcpClient
*/

#include "QtTcpClient.hpp"

using namespace Babel::Network;

QtTcpClient::QtTcpClient(const std::string &ipv4, unsigned short port)
{
    _socket.connectToHost(QString::fromStdString(ipv4), port);
}

QtTcpClient::~QtTcpClient()
{
}

void QtTcpClient::send(const std::string &data)
{
    return;
}

std::string QtTcpClient::receive()
{
    return "";
}