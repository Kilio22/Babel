/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

#include "IUser.hpp"

namespace Babel::Server
{
    class User : public IUser {
    public:
        User(const boost::shared_ptr<ITcpClient> &tcpClient);
        ~User();

        boost::shared_ptr<ITcpClient> getTcpClient() const final;
        const std::string &getUsername() const final;
        void setUsername(const std::string &) final;
        bool isLoggedIn() const final;
        void setLoggedIn(bool loggedIn) final;

    private:
        std::string username;
        boost::shared_ptr<ITcpClient> tcpClient;
        bool loggedIn;
    };
} // namespace Babel::Server

#endif /* !USER_HPP_ */
