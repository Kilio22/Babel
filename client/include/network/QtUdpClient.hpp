/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtUdpClient
*/

#ifndef QTUDPCLIENT_HPP_
#define QTUDPCLIENT_HPP_

#include "IUdpClient.hpp"
#include <QtCore/QObject>
#include <QtNetwork/QNetworkDatagram>
#include <QtNetwork/QUdpSocket>
#include <memory>
#include <queue>

namespace Babel::Client::Network
{
    class QtUdpClient : public QObject, public IUdpClient
    {
        Q_OBJECT
        Q_INTERFACES(Babel::Client::Network::IUdpClient)

    public:
        QtUdpClient();
        ~QtUdpClient() = default;

        void connect(unsigned short port) override;
        void closeConnection() override;
        void send(const DataPacket &dataPacket) const override;
        DataPacket getData() override;

        void sendPacketsTo(std::vector<std::pair<std::string, unsigned short>> hosts);

    signals:
        void dataAvailable();

    private slots:
        void readPendingDatagrams();

    private:
        std::unique_ptr<QUdpSocket> socket;
        std::queue<QNetworkDatagram> dataQueue;
    };
}

#endif /* !QTUDPCLIENT_HPP_ */
