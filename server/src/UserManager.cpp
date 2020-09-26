/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** UserManager
*/

#include "UserManager.hpp"
#include "commands/CommandFactory.hpp"

Babel::Server::UserManager Babel::Server::UserManager::userManagerInstance;

Babel::Server::UserManager &Babel::Server::UserManager::getInstance()
{
    return userManagerInstance;
}

Babel::Server::UserManager::UserManager() { }

Babel::Server::UserManager::~UserManager() { }

void Babel::Server::UserManager::addUser(std::unique_ptr<Babel::Server::IUser> newUser)
{
    this->m_userList.push_back(std::move(newUser));
}

void Babel::Server::UserManager::removeUserByTcpClient(const ITcpClient *tcpClient)
{
    for (const auto &user : this->m_userList) {
        if (user->getTcpClient().get() == tcpClient && user->isInCall()) {
            CommandFactory::createCommandFromCommandType(Commands::COMMAND_TYPE::STOP_CALL)->handle(nullptr, 0, user.get());
        }
        if (user->getTcpClient().get() == tcpClient) {
            break;
        }
    }
    this->m_userList.erase(std::remove_if(this->m_userList.begin(), this->m_userList.end(),
                             [tcpClient](const std::unique_ptr<IUser> &user) { return user->getTcpClient().get() == tcpClient; }),
        this->m_userList.end());
}

Babel::Server::IUser *Babel::Server::UserManager::getUserByTcpClient(const ITcpClient *tcpClient) const
{
    for (const auto &user : this->m_userList) {
        if (user->getTcpClient().get() == tcpClient) {
            return user.get();
        }
    }
    return nullptr;
}

Babel::Server::IUser *Babel::Server::UserManager::getUserByUsername(const std::string &username) const
{
    for (const auto &user : this->m_userList) {
        if (user->getUsername() == username) {
            return user.get();
        }
    }
    return nullptr;
}
