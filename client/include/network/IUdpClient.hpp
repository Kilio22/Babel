/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IUdpClient
*/

#ifndef IUDPCLIENT_HPP_
#define IUDPCLIENT_HPP_

#include <QtCore/QObject>

namespace Babel::Client::Network
{
    class IUdpClient
    {
    public:
        struct DataPacket {
            std::vector<char> data;
            std::string host;
            unsigned short port;
        };

    public:
        virtual ~IUdpClient() = default;

        virtual void connect(unsigned short port) = 0;
        virtual void closeConnection() = 0;
        virtual void send(const DataPacket &dataPacket) const = 0;
        virtual DataPacket getData() = 0;

    signals:
        virtual void dataAvailable() = 0;
    };
}

Q_DECLARE_INTERFACE(Babel::Client::Network::IUdpClient, "Babel::Client::Network::IUdpClient")

#endif /* !IUDPCLIENT_HPP_ */
