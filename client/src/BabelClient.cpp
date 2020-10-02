/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelClient
*/

#include "BabelClient.hpp"
#include "exceptions.h"
#include "WindowManager.hpp"
#include "ServiceLocator.hpp"
#include "CommandManager.hpp"
#include <iostream>
#include <boost/lexical_cast.hpp>

void Babel::Client::BabelClient::create(int ac, char *av[])
{
    if (ac != 4)
        throw Exceptions::BadArgumentsException(
            "Bad args number, got: " + std::to_string(ac) + " but 4 are needed.", "Babel::Client::BabelClient::BabelClient");
    try {
        this->serveurIp = boost::lexical_cast<std::string>(av[1]);
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
    try {
        this->clientIp = boost::lexical_cast<std::string>(av[3]);
    } catch (const std::exception &e) {
        throw Exceptions::BadArgumentsException(
            "Bad argument, got: \"" + std::string(av[3]) + "\" but a valid ip is needed: " + std::string(e.what()) + ".",
            "Babel::Client::BabelClient::BabelClient");
    }
    ServiceLocator::getInstance().get<Babel::Client::CommandManager>().create(this->serveurIp, this->port, this->clientIp);
}
