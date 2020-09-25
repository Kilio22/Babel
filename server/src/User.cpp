/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** User
*/

#include "User.hpp"
#include "UserManager.hpp"
#include "commands/CommandParser.hpp"
#include <utility>

Babel::Server::User::User(const boost::shared_ptr<ITcpClient> &tcpClient)
    : tcpClient(tcpClient)
    , loggedIn(false)
    , inCall(false)
{
}

Babel::Server::User::~User() { }

boost::shared_ptr<Babel::Server::ITcpClient> Babel::Server::User::getTcpClient() const
{
    return this->tcpClient;
}

const std::string &Babel::Server::User::getUsername() const
{
    return this->username;
}

void Babel::Server::User::setUsername(const std::string &newUsername)
{
    this->username.assign(newUsername);
}

bool Babel::Server::User::isLoggedIn() const
{
    return this->loggedIn;
}

void Babel::Server::User::setLoggedIn(bool loggedIn)
{
    this->loggedIn = loggedIn;
}

void Babel::Server::User::tcpClientHasData() const
{
    std::pair<size_t, const unsigned char *> data = this->tcpClient->getData();

    CommandParser::getInstance().parseCommand(data.second, data.first, UserManager::getInstance().getUserByTcpClient(this->tcpClient.get()));
}

bool Babel::Server::User::isInCall() const
{
    return this->inCall;
}

void Babel::Server::User::setInCall(bool inCall)
{
    this->inCall = inCall;
}
const std::vector<std::string> &Babel::Server::User::getCalledUsers() const
{
    return this->calledUsers;
}

void Babel::Server::User::setCalledUsers(const std::vector<std::string> &calledUsers)
{
    this->calledUsers = calledUsers;
}