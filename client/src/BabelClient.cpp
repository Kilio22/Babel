/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelClient
*/

#include "BabelClient.hpp"
#include "exceptions.h"
#include <boost/lexical_cast.hpp>
#include "QtTcpClient.hpp"
#include "WindowManager.hpp"
#include "ServiceLocator.hpp"
#include "CommandManager.hpp"
#include "CommandParser.hpp"
#include <iostream>

Babel::Client::BabelClient::BabelClient(QObject *parent)
    : QObject(parent)
{
}

void Babel::Client::BabelClient::create(int ac, char *av[])
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
    tcpClient = new Babel::Client::Network::QtTcpClient();
    QObject::connect(dynamic_cast<QObject *>(tcpClient), SIGNAL (dataAvailable()), this, SLOT (onDataAvailable()));
    ServiceLocator::getInstance().get<Babel::Client::CommandManager>().create(this->ip, this->port, this->tcpClient);
    ServiceLocator::getInstance().get<WindowManager>().setState(WindowManager::State::Login);
}

void Babel::Client::BabelClient::onDataAvailable()
{
    std::cout << "There is some data !" << std::endl;
    std::pair<size_t, const unsigned char *> data = tcpClient->getData();
    for (size_t i = 0; i < 4096; i++) {
        if (data.second[i] != 0) {
            std::cout << data.second[i] << std::endl;
        }
    }
    CommandParser::getInstance().parseCommand(data.second, data.first);
}

#include "moc_BabelClient.cpp"