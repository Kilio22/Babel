/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtUdpClient
*/

#include "QtUdpClient.hpp"
#include "QtUcpClientException.hpp"

Babel::Client::Network::QtUdpClient::QtUdpClient()
    : socket(std::make_unique<QUdpSocket>())
{
    QObject::connect(this->socket.get(), &QUdpSocket::readyRead, this, &QtUdpClient::readPendingDatagrams);
}

void Babel::Client::Network::QtUdpClient::connect(unsigned short port)
{
    if (this->socket->bind(QHostAddress::AnyIPv4, port) == false)
        throw Exceptions::QtUcpClientException(ERROR_STR, "connect");
}

void Babel::Client::Network::QtUdpClient::send(const char *data, long size, const std::string &host, unsigned short port) const
{
    QHostAddress addr(QString::fromStdString(host));

    this->socket->writeDatagram(data, size, addr, port);
}

char *Babel::Client::Network::QtUdpClient::getData()
{
    auto &datagram = this->dataQueue.front();
    char *bytes = datagram.data().data();

    this->dataQueue.pop();
    return bytes;
}

void Babel::Client::Network::QtUdpClient::readPendingDatagrams()
{
    while (this->socket->hasPendingDatagrams()) {
        this->dataQueue.push(this->socket->receiveDatagram());
    }
    emit this->dataAvailable();
}

#include "moc_QtUdpClient.cpp"
