/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** User
*/

#include "User.hpp"

Babel::Server::User::User(const boost::shared_ptr<ITcpClient> &tcpClient)
    : tcpClient(tcpClient)
    , loggedIn(false)
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