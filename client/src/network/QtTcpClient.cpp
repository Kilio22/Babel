/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtTcpClient
*/

#include "QtTcpClient.hpp"
#include "QtTcpClientException.hpp"
#include <iostream>

Babel::Client::Network::QtTcpClient::QtTcpClient(const std::string &ipv4, unsigned short port, QObject *parent)
    : QObject(parent), ip(ipv4), port(port)
{
    socket = new QTcpSocket();
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(handleReadyRead()));
}

Babel::Client::Network::QtTcpClient::~QtTcpClient()
{
}

bool Babel::Client::Network::QtTcpClient::send(const unsigned char *data, size_t size)
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write((char *)data, size);
        return socket->waitForBytesWritten(5000);
    } else
        return false;
}

void Babel::Client::Network::QtTcpClient::connectSocket()
{
    socket->connectToHost(QString::fromStdString(ip), port);
    if (!socket->waitForConnected(5000)) {
        throw Babel::Client::Exceptions::QtTcpClientException(
            "Can't connect to server: " + socket->errorString().toStdString(), "Babel::Client::Network::QtTcpClient::QtTcpClient");
    }
}

bool Babel::Client::Network::QtTcpClient::isConnected() const
{
    if (socket->state() == QAbstractSocket::ConnectedState)
        return true;
    return false;
}

void Babel::Client::Network::QtTcpClient::connected()
{
    std::cout << "Client connected to the server !" << std::endl;
}

void Babel::Client::Network::QtTcpClient::disconnected()
{
    std::cout << "Server disconnected !" << std::endl;
}

void Babel::Client::Network::QtTcpClient::handleReadyRead()
{
    std::cout << "Ready to read !" << std::endl;
}

#include "moc_QtTcpClient.cpp"