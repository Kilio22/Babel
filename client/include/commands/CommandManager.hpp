/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandManager
*/

#ifndef COMMANDMANAGER_HPP_
#define COMMANDMANAGER_HPP_

#include "ITcpClient.hpp"

namespace Babel::Client
{
    class CommandManager {
        public:
            CommandManager();
            ~CommandManager() = default;

            void create(const std::string &ip, unsigned short port, Network::ITcpClient *tcpClient);
            bool connect();
            void signup(const std::string &username, const std::string &password);
            void login(const std::string &username, const std::string &password);
        private:
            unsigned short port;
            std::string ip;
            Network::ITcpClient *tcpClient;
    };
}

#endif /* !COMMANDMANAGER_HPP_ */
