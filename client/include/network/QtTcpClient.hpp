/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** QtTcpClient
*/

#ifndef QTTCPCLIENT_HPP_
#define QTTCPCLIENT_HPP_

#include "ITcpClient.hpp"
#include <QtNetwork/QTcpSocket>
#include <QtCore/QObject>

namespace Babel::Client::Network
{
    const int readSize = 4096;

    class QtTcpClient : public QObject, public ITcpClient
    {
        Q_OBJECT
        Q_INTERFACES(Babel::Client::Network::ITcpClient)
        public:
            explicit QtTcpClient(const std::string &ipv4, unsigned short port, QObject *parent = 0);
            ~QtTcpClient();

            bool send(const unsigned char *data, size_t size) const;
            char *getData();
            void connectSocket();
            bool isConnected() const;
        signals:
            void dataAvailable();
        private slots:
            void connected();
            void disconnected();
            void handleReadyRead();

        private:
            QTcpSocket *socket;
            std::string ip;
            unsigned short port;
            std::array<char, readSize> data;
    };
}

#endif /* !QTTCPCLIENT_HPP_ */
