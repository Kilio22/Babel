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
        User(boost::shared_ptr<ITcpClient> tcpClient);
        ~User();

        const boost::shared_ptr<ITcpClient> &getTcpClient() const final;
        const std::string &getUsername() const final;
        void setUsername(const std::string &) final;

    protected:
    private:
        std::string username;
        boost::shared_ptr<ITcpClient> tcpClient;
    };
} // namespace Babel::Server

#endif /* !USER_HPP_ */
