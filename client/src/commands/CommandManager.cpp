/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandManager
*/

#include "CommandManager.hpp"
#include "CommandParser.hpp"
#include "QtTcpClient.hpp"
#include "exceptions.h"
#include <iostream>
#include <sstream>

Babel::Client::CommandManager::CommandManager() { }

void Babel::Client::CommandManager::create(const std::string &serveurIp, unsigned short port, const std::string &clientIp)
{
    this->serveurIp = serveurIp;
    this->port = port;
    this->clientIp = clientIp;
    this->tcpClient = std::make_unique<Babel::Client::Network::QtTcpClient>();
    QObject::connect(dynamic_cast<QObject *>(this->tcpClient.get()), SIGNAL(dataAvailable()), this, SLOT(onDataAvailable()));
}

bool Babel::Client::CommandManager::connect()
{
    try {
        if (tcpClient->isConnected())
            return true;
        tcpClient->connectSocket(this->serveurIp, this->port);
        return true;
    } catch (Babel::Client::Exceptions::QtTcpClientException &e) {
        std::cerr << e.getComponent() << ": " << e.what() << std::endl;
        return false;
    }
}

void Babel::Client::CommandManager::signup(const std::string &username, const std::string &password)
{
    if (connect()) {
        Commands::RegisterRequest registerRequest = { Commands::Header(Commands::COMMAND_TYPE::REGISTER) };
        strcpy(registerRequest.username, username.c_str());
        strcpy(registerRequest.password, password.c_str());
        tcpClient->send(reinterpret_cast<const unsigned char *>(&registerRequest), sizeof(Commands::RegisterRequest));
        return;
    } else {
        throw Exceptions::SignupFailedException("Can't connect to server.", "Babel::Client::CommandManager::signup");
    }
}

void Babel::Client::CommandManager::login(const std::string &username, const std::string &password)
{
    if (connect()) {
        Commands::LoginRequest loginRequest = { Commands::Header(Commands::COMMAND_TYPE::LOGIN) };
        strcpy(loginRequest.username, username.c_str());
        strcpy(loginRequest.password, password.c_str());
        strcpy(loginRequest.ip, this->clientIp.c_str());
        tcpClient->send(reinterpret_cast<const unsigned char *>(&loginRequest), sizeof(Commands::LoginRequest));
        return;
    } else {
        throw Exceptions::LoginFailedException("Can't connect to server.", "Babel::Client::CommandManager::login");
    }
}

void Babel::Client::CommandManager::addContact(const std::string &username)
{
    if (connect()) {
        Commands::AddContactRequest contactRequest = { Commands::Header(Commands::COMMAND_TYPE::ADD_CONTACT) };
        strcpy(contactRequest.username, username.c_str());
        tcpClient->send(reinterpret_cast<const unsigned char *>(&contactRequest), sizeof(Commands::AddContactRequest));
        return;
    } else {
        throw Exceptions::LoginFailedException("Can't connect to server.", "Babel::Client::CommandManager::addContact");
    }
}

void Babel::Client::CommandManager::getContacts()
{
    if (connect()) {
        const Commands::Header getContactRequest(Commands::COMMAND_TYPE::GET_CONTACTS);
        tcpClient->send(reinterpret_cast<const unsigned char *>(&getContactRequest), sizeof(Commands::Header));
        return;
    } else {
        throw Exceptions::LoginFailedException("Can't connect to server.", "Babel::Client::CommandManager::getContacts");
    }
}

void Babel::Client::CommandManager::startCall(std::vector<std::string> users)
{
    if (connect()) {
        std::stringbuf b;
        std::ostream os(&b);
        std::vector<Commands::Username> usernames;
        for (int i = 0; i < users.size(); i++)
            usernames.push_back(users.at(i));
        const Commands::Header startCallRequest(Commands::COMMAND_TYPE::START_CALL);
        os.write(reinterpret_cast<const char *>(&startCallRequest), sizeof(Commands::Header));
        os.write(reinterpret_cast<const char *>(usernames.data()), sizeof(Commands::Username) * usernames.size());
        tcpClient->send(
            reinterpret_cast<const unsigned char *>(b.str().c_str()), sizeof(Commands::Username) * usernames.size() + sizeof(Commands::Header));
        return;
    } else {
        throw Exceptions::LoginFailedException("Can't connect to server.", "Babel::Client::CommandManager::startCall");
    }
}

void Babel::Client::CommandManager::stopCall()
{
    if (connect()) {
        const Commands::Header stopCallRequest(Commands::COMMAND_TYPE::STOP_CALL);
        tcpClient->send(reinterpret_cast<const unsigned char *>(&stopCallRequest), sizeof(Commands::Header));
        return;
    } else {
        throw Exceptions::LoginFailedException("Can't connect to server.", "Babel::Client::CommandManager::stopCall");
    }
}

void Babel::Client::CommandManager::disconnect()
{
    if (connect()) {
        const Commands::Header disconnectRequest(Commands::COMMAND_TYPE::DISCONNECT);
        tcpClient->send(reinterpret_cast<const unsigned char *>(&disconnectRequest), sizeof(Commands::Header));
        return;
    } else {
        throw Exceptions::LoginFailedException("Can't connect to server.", "Babel::Client::CommandManager::stopCall");
    }
}

void Babel::Client::CommandManager::onDataAvailable()
{
    std::pair<std::size_t, const unsigned char *> data = tcpClient->getData();
    for (std::size_t i = 0; i < 4096; i++) {
        if (data.second[i] != 0) {
            // std::cout << data.second[i] << std::endl;
        }
    }
    CommandParser::getInstance().parseCommand(data.second, data.first);
}

#include "moc_CommandManager.cpp"