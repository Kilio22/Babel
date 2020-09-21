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

namespace Babel::Network
{
    class QtTcpClient : public ITcpClient 
    {
        public:
            QtTcpClient(const std::string &ipv4, unsigned short port);
            ~QtTcpClient();

            void send(const std::string &data);
            std::string receive();
        protected:
        private:
            QTcpSocket _socket;
    };
}

#endif /* !QTTCPCLIENT_HPP_ */
