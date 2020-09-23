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
    class QtTcpClient : public QObject, public ITcpClient
    {
        Q_OBJECT
        public:
            explicit QtTcpClient(const std::string &ipv4, unsigned short port, QObject *parent = 0);
            ~QtTcpClient();

            bool send(const unsigned char *data);
        signals:
    
        public slots:
            void connected();
            void disconnected();
            void handleReadyRead();

        private:
            QTcpSocket *socket;
    };
}

#endif /* !QTTCPCLIENT_HPP_ */
