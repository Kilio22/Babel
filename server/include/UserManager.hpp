/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** UserManager
*/

#ifndef USERMANAGER_HPP_
#define USERMANAGER_HPP_

#include "IUser.hpp"
#include <vector>

namespace Babel::Server
{
    class UserManager {
    public:
        ~UserManager() = default;

        UserManager(const UserManager &) = delete;
        UserManager &operator=(const UserManager &) = delete;

        static UserManager &getInstance();

        void addUser(std::unique_ptr<IUser>);
        void removeUserByTcpClient(const ITcpClient *);
        IUser *getUserByTcpClient(const ITcpClient *) const;
        IUser *getUserByUsername(const std::string &) const;

    private:
        UserManager() = default;

    private:
        static UserManager userManagerInstance;
        std::vector<std::unique_ptr<IUser>> m_userList;
    };
} // namespace Babel::Server

#endif /* !USERMANAGER_HPP_ */
