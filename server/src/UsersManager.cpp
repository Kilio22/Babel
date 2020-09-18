/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** UsersManager
*/

#include "UsersManager.hpp"

Babel::Server::UsersManager Babel::Server::UsersManager::usersManagerInstance;

Babel::Server::UsersManager &Babel::Server::UsersManager::getInstance()
{
    return usersManagerInstance;
}

Babel::Server::UsersManager::UsersManager() { }

Babel::Server::UsersManager::~UsersManager() { }

void Babel::Server::UsersManager::addUser(const std::shared_ptr<Babel::Server::IUser> &newUser)
{
    this->userList.push_back(newUser);
}

void Babel::Server::UsersManager::removeUserByTcpClient(const boost::shared_ptr<ITcpClient> &tcpClient)
{
    this->userList.erase(std::remove_if(this->userList.begin(), this->userList.end(),
        [tcpClient](const std::shared_ptr<IUser> &user) { return user->getTcpClient().get() == tcpClient.get(); }));
}

std::shared_ptr<Babel::Server::IUser> Babel::Server::UsersManager::getUserByTcpClient(const boost::shared_ptr<ITcpClient> &tcpClient) const
{
    for (const auto &user : this->userList) {
        if (user->getTcpClient() == tcpClient) {
            return user;
        }
    }
    return nullptr;
}
