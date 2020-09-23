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
#include <iostream>

Babel::Client::BabelClient::BabelClient()
: connected(false)
{
    ServiceLocator::getInstance().get<WindowManager>().setState(WindowManager::State::Login);
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
}

bool Babel::Client::BabelClient::connect()
{
    try {
        if (connected == false) {
            tcpClient = new Babel::Client::Network::QtTcpClient(this->ip, this->port);
            connected = true;
        }
        return true;
    } catch (Babel::Client::Exceptions::QtTcpClientException &e) {
        connected = false;
        std::cerr << e.getComponent() << ": " << e.what() << std::endl;
        return false;
    }
}

void Babel::Client::BabelClient::signup(const std::string &username, const std::string &password)
{
    if (connect()) {
        return;
    } else {
        throw Exceptions::SignupFailedException(
            "Can't connect to server.", "Babel::Client::BabelClient::signup");
    }
}