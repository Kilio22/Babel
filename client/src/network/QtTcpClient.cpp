/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtTcpClient
*/

#include "QtTcpClient.hpp"
#include "QtTcpClientException.hpp"
#include <iostream>

Babel::Client::Network::QtTcpClient::QtTcpClient()
{
    socket = std::make_unique<QTcpSocket>();
    connect(this->socket.get(), SIGNAL(connected()), this, SLOT(connected()));
    connect(this->socket.get(), SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(this->socket.get(), SIGNAL(readyRead()), this, SLOT(handleReadyRead()));
}

Babel::Client::Network::QtTcpClient::~QtTcpClient() { }

bool Babel::Client::Network::QtTcpClient::send(const unsigned char *data, std::size_t size) const
{
    socket->write((char *)data, size);
    return socket->waitForBytesWritten(5000);
}

std::pair<std::size_t, const unsigned char *> Babel::Client::Network::QtTcpClient::getData()
{
    std::pair<std::size_t, const unsigned char *> data;
    data.first = this->bytes_transfered;
    data.second = reinterpret_cast<unsigned char *>(this->data.data());
    return data;
}

void Babel::Client::Network::QtTcpClient::connectSocket(const std::string &ipv4, unsigned short port)
{
    socket->connectToHost(QString::fromStdString(ipv4), port);
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
}

void Babel::Client::Network::QtTcpClient::disconnected()
{
}

void Babel::Client::Network::QtTcpClient::handleReadyRead()
{
    this->data.fill('\0');
    this->bytes_transfered = socket->read(this->data.data(), readSize);
    if ((int)this->bytes_transfered == -1)
        return;
    emit this->dataAvailable();
}

#include "moc_QtTcpClient.cpp"