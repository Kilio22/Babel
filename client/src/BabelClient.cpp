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
#include "Commands.hpp"
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
    tcpClient = new Babel::Client::Network::QtTcpClient(this->ip, this->port);
    QObject::connect(dynamic_cast<QObject *>(tcpClient), SIGNAL (dataAvailable()), this, SLOT (onDataAvailable()));
    ServiceLocator::getInstance().get<WindowManager>().setState(WindowManager::State::Login);
}

void Babel::Client::BabelClient::onDataAvailable()
{
    std::cout << "There is some data !" << std::endl;
    char *data = tcpClient->getData();
    for (size_t i = 0; i < 4096; i++) {
        if (data[i] != 0) {
            std::cout << data[i] << std::endl;
        }
    }
}

bool Babel::Client::BabelClient::connect()
{
    try {
        if (tcpClient->isConnected())
            return true;
        tcpClient->connectSocket();
        return true;
    } catch (Babel::Client::Exceptions::QtTcpClientException &e) {
        std::cerr << e.getComponent() << ": " << e.what() << std::endl;
        return false;
    }
}

void Babel::Client::BabelClient::signup(const std::string &username, const std::string &password)
{
    if (connect()) {
        Commands::RegisterRequest registerRequest = { Commands::Header(Commands::COMMAND_TYPE::REGISTER)};
        strcpy(registerRequest.username, username.c_str());
        strcpy(registerRequest.password, password.c_str());
        tcpClient->send(reinterpret_cast<const unsigned char *>(&registerRequest), sizeof(Commands::RegisterRequest));
        return;
    } else {
        throw Exceptions::SignupFailedException(
            "Can't connect to server.", "Babel::Client::BabelClient::signup");
    }
}

void Babel::Client::BabelClient::login(const std::string &username, const std::string &password)
{
    if (connect()) {
        Commands::LoginRequest loginRequest = { Commands::Header(Commands::COMMAND_TYPE::LOGIN)};
        strcpy(loginRequest.username, username.c_str());
        strcpy(loginRequest.password, password.c_str());
        tcpClient->send(reinterpret_cast<const unsigned char *>(&loginRequest), sizeof(Commands::LoginRequest));
        return;
    } else {
        throw Exceptions::LoginFailedException(
            "Can't connect to server.", "Babel::Client::BabelClient::signup");
    }
}

#include "moc_BabelClient.cpp"