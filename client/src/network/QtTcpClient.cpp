/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtTcpClient
*/

#include "QtTcpClient.hpp"
#include "QtTcpClientException.hpp"
#include "Commands.hpp"
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
    socket->write((char *)data, size);
    return socket->waitForBytesWritten(5000);
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
    std::fill(std::begin(this->data), std::end(this->data), '\0');
    size_t bytes_transfered = socket->read(data, readSize);
    if (bytes_transfered == -1)
        return;
    for (size_t i = 0; i < 4096; i++) {
        if (this->data[i] != 0) {
            std::cout << (char)this->data[i] << std::endl;
        }
    }
    std::cout << bytes_transfered << " bytes !" << std::endl; //debug
}

#include "moc_QtTcpClient.cpp"