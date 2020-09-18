/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** UsersManager
*/

#ifndef USERSMANAGER_HPP_
#define USERSMANAGER_HPP_

#include "IUser.hpp"
#include <vector>

namespace Babel::Server
{
    class UsersManager {
    public:
        ~UsersManager();

        static UsersManager &getInstance();

        void addUser(const std::shared_ptr<IUser> &);
        void removeUserByTcpClient(const boost::shared_ptr<ITcpClient> &);
        std::shared_ptr<IUser> getUserByTcpClient(const boost::shared_ptr<ITcpClient> &) const;

    private:
        UsersManager();
        UsersManager(const UsersManager &) = delete;
        UsersManager &operator=(const UsersManager &) = delete;
        std::vector<std::shared_ptr<IUser>> userList;

        static UsersManager usersManagerInstance;
    };
} // namespace Babel::Server

#endif /* !USERSMANAGER_HPP_ */
