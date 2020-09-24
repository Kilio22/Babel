/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandManager
*/

#include "CommandManager.hpp"
#include "Commands.hpp"
#include "exceptions.h"
#include <iostream>

Babel::Client::CommandManager::CommandManager()
{
}

void Babel::Client::CommandManager::create(const std::string &ip, unsigned short port, Network::ITcpClient *tcpClient)
{
    this->ip = ip;
    this->port = port;
    this->tcpClient = tcpClient;
}

bool Babel::Client::CommandManager::connect()
{
    try {
        if (tcpClient->isConnected())
            return true;
        tcpClient->connectSocket(this->ip, this->port);
        return true;
    } catch (Babel::Client::Exceptions::QtTcpClientException &e) {
        std::cerr << e.getComponent() << ": " << e.what() << std::endl;
        return false;
    }
}

void Babel::Client::CommandManager::signup(const std::string &username, const std::string &password)
{
    if (connect()) {
        Commands::RegisterRequest registerRequest = { Commands::Header(Commands::COMMAND_TYPE::REGISTER)};
        strcpy(registerRequest.username, username.c_str());
        strcpy(registerRequest.password, password.c_str());
        tcpClient->send(reinterpret_cast<const unsigned char *>(&registerRequest), sizeof(Commands::RegisterRequest));
        return;
    } else {
        throw Exceptions::SignupFailedException(
            "Can't connect to server.", "Babel::Client::CommandManager::signup");
    }
}

void Babel::Client::CommandManager::login(const std::string &username, const std::string &password)
{
    if (connect()) {
        Commands::LoginRequest loginRequest = { Commands::Header(Commands::COMMAND_TYPE::LOGIN)};
        strcpy(loginRequest.username, username.c_str());
        strcpy(loginRequest.password, password.c_str());
        tcpClient->send(reinterpret_cast<const unsigned char *>(&loginRequest), sizeof(Commands::LoginRequest));
        return;
    } else {
        throw Exceptions::LoginFailedException(
            "Can't connect to server.", "Babel::Client::CommandManager::signup");
    }
}