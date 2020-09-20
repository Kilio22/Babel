/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** UserManager
*/

#include "UserManager.hpp"

Babel::Server::UserManager Babel::Server::UserManager::userManagerInstance;

Babel::Server::UserManager &Babel::Server::UserManager::getInstance()
{
    return userManagerInstance;
}

Babel::Server::UserManager::UserManager() { }

Babel::Server::UserManager::~UserManager() { }

void Babel::Server::UserManager::addUser(const std::shared_ptr<Babel::Server::IUser> &newUser)
{
    this->userList.push_back(newUser);
}

void Babel::Server::UserManager::removeUserByTcpClient(const ITcpClient *tcpClient)
{
    this->userList.erase(std::remove_if(this->userList.begin(), this->userList.end(),
                             [tcpClient](const std::shared_ptr<IUser> &user) { return user->getTcpClient().get() == tcpClient; }),
        this->userList.end());
}

std::shared_ptr<Babel::Server::IUser> Babel::Server::UserManager::getUserByTcpClient(const ITcpClient *tcpClient) const
{
    for (const auto &user : this->userList) {
        if (user->getTcpClient().get() == tcpClient) {
            return user;
        }
    }
    return nullptr;
}
