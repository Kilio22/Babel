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
        ~UserManager();

        static UserManager &getInstance();

        void addUser(const std::shared_ptr<IUser> &);
        void removeUserByTcpClient(const ITcpClient *);
        std::shared_ptr<IUser> getUserByTcpClient(const ITcpClient *) const;

    private:
        UserManager();
        UserManager(const UserManager &) = delete;
        UserManager &operator=(const UserManager &) = delete;

        std::vector<std::shared_ptr<IUser>> userList;

        static UserManager userManagerInstance;
    };
} // namespace Babel::Server

#endif /* !USERMANAGER_HPP_ */
