/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelClient
*/

#ifndef BABELCLIENT_HPP_
#define BABELCLIENT_HPP_

#include "IClient.hpp"
#include "ITcpClient.hpp"
#include <QtCore/QObject>
#include <string>

namespace Babel::Client
{
    class BabelClient : public QObject, public IClient {
        Q_OBJECT
        public:
            BabelClient(QObject *parent = 0);
            ~BabelClient() = default;

            void create(int ac, char *av[]);
            bool connect() final;
            void signup(const std::string &username, const std::string &password) final;
            void login(const std::string &username, const std::string &password) final;
        private slots:
            void onDataAvailable();
        private:
            unsigned short port;
            std::string ip;
            Network::ITcpClient *tcpClient;
    };
}

#endif /* !BABELCLIENT_HPP_ */
