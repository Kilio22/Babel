/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelClient
*/

#include "BabelClient.hpp"
#include "QtTcpClientException.hpp"
#include "BadArgumentsException.hpp"
#include "QtTcpClient.hpp"
#include <boost/lexical_cast.hpp>
#include <iostream>

Babel::Client::BabelClient::BabelClient(int ac, const char *av[])
{
    if (ac != 3)
        throw Exceptions::BadArgumentsException(
            "Bad args number, got: " + std::to_string(ac) + "but 3 are needed.", "Babel::Client::BabelClient::BabelClient");
    try {
        this->ip = boost::lexical_cast<std::string>(av[1]);
    } catch (const std::exception &e) {
        throw Exceptions::BadArgumentsException(
            "Bad argument, got: \"" + std::string(av[1]) + "\" but a valid ip is needed: " + std::string(e.what()) + ".",
            "Babel::Client::BabelClient::BabelClient");
    }
    try {
        this->port = boost::lexical_cast<unsigned short>(av[2]);
    } catch (const std::exception &e) {
        throw Exceptions::BadArgumentsException(
            "Bad argument, got: \"" + std::string(av[2]) + "\" but a valid port number is needed: " + std::string(e.what()) + ".",
            "Babel::Client::BabelClient::BabelClient");
    }
}

void Babel::Client::BabelClient::run()
{
    try {
        std::unique_ptr<Babel::Client::Network::ITcpClient> tcpClient = std::make_unique<Babel::Client::Network::QtTcpClient>(this->ip, this->port);

        while (1) {
        
        }
    } catch (Babel::Client::Exceptions::QtTcpClientException &e) {
        throw e;
    }
}