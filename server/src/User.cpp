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
        : m_tcpClient(tcpClient),
          m_loggedIn(false),
          m_inCall(false)
{
}

boost::shared_ptr<Babel::Server::ITcpClient> Babel::Server::User::getTcpClient() const
{
    return this->m_tcpClient;
}

const std::string &Babel::Server::User::getUsername() const
{
    return this->m_username;
}

void Babel::Server::User::setUsername(const std::string &newUsername)
{
    this->m_username.assign(newUsername);
}

bool Babel::Server::User::isLoggedIn() const
{
    return this->m_loggedIn;
}

void Babel::Server::User::setLoggedIn(bool loggedIn)
{
    this->m_loggedIn = loggedIn;
}

void Babel::Server::User::tcpClientHasData() const
{
    std::pair<std::size_t, const unsigned char *> data = this->m_tcpClient->getData();

    CommandParser::getInstance().parseCommand(data.second, data.first, UserManager::getInstance().getUserByTcpClient(this->m_tcpClient.get()));
}

bool Babel::Server::User::isInCall() const
{
    return this->m_inCall;
}

void Babel::Server::User::setInCall(bool inCall)
{
    this->m_inCall = inCall;
}

const std::vector<std::string> &Babel::Server::User::getCalledUsers() const
{
    return this->m_calledUsers;
}

void Babel::Server::User::setCalledUsers(const std::vector<std::string> &calledUsers)
{
    this->m_calledUsers = calledUsers;
}
