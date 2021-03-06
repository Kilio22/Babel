/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtUdpClient
*/

#include "QtUdpClient.hpp"
#include "QtUcpClientException.hpp"
#include <QtTest/QSignalSpy>
#include <iostream>

Babel::Client::Network::QtUdpClient::QtUdpClient()
    : socket(std::make_unique<QUdpSocket>())
{
    QObject::connect(this->socket.get(), &QUdpSocket::readyRead, this, &QtUdpClient::readPendingDatagrams);
}

void Babel::Client::Network::QtUdpClient::connect(unsigned short port)
{
    std::cout << "Binding..." << std::endl;
    if (!this->socket->bind(QHostAddress::AnyIPv4, port)) {
        std::cerr << "Bind failed" << std::endl;
        throw Exceptions::QtUcpClientException(ERROR_STR, "connect");
    }
    std::cout << "UDP client connected." << std::endl;
}

void Babel::Client::Network::QtUdpClient::closeConnection()
{
    this->socket->disconnectFromHost();
    std::cout << "UDP client disconnected with state: " << this->socket->state() << std::endl;
}

void Babel::Client::Network::QtUdpClient::send(const DataPacket &dataPacket) const
{
    const auto &[data, host, port] = dataPacket;
    QHostAddress addr(QString::fromStdString(host));

    this->socket->writeDatagram(data.data(), data.size(), addr, port);
}

Babel::Client::Network::IUdpClient::DataPacket Babel::Client::Network::QtUdpClient::getData()
{
    QNetworkDatagram &datagram = this->dataQueue.front();
    QByteArray byteArray = datagram.data();
    DataPacket dataPacket;

    dataPacket.host = datagram.senderAddress().toString().toStdString();
    dataPacket.port = datagram.senderPort();
    dataPacket.data.assign(byteArray.begin(), byteArray.end());
    this->dataQueue.pop();
    return dataPacket;
}

void Babel::Client::Network::QtUdpClient::readPendingDatagrams()
{
    while (this->socket->hasPendingDatagrams()) {
        this->dataQueue.push(this->socket->receiveDatagram());
        emit this->dataAvailable();
    }
}

#include "moc_QtUdpClient.cpp"
