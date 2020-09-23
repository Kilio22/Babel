/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelClient
*/

#include "BabelClient.hpp"
#include "QtTcpClientException.hpp"
#include "BadArgumentsException.hpp"
#include <boost/lexical_cast.hpp>
#include "QtTcpClient.hpp"
#include "WindowManager.hpp"
#include "ServiceLocator.hpp"
#include <iostream>

Babel::Client::BabelClient::BabelClient(int ac, char *av[])
    : connected(false)
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
    ServiceLocator::getInstance().get<WindowManager>().setState(WindowManager::State::Login);
}

bool Babel::Client::BabelClient::connect()
{
    try {
        //TODO Antoine
        // ça faudrait que ça se fasse uniquement quand on veut faire des requetes genre login / signup. pas à chaque fois.
        // Y'a des TODO dans les fichiers LoginWindow.cpp & SignupWindow.cpp pour savoir où faire quoi tkt.
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