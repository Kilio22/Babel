/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IUser
*/

#ifndef IUSER_HPP_
#define IUSER_HPP_

#include "ITcpClient.hpp"
#include <boost/shared_ptr.hpp>
#include <string>

namespace Babel::Server
{
    class IUser {
    public:
        virtual ~IUser() = default;

        virtual boost::shared_ptr<ITcpClient> getTcpClient() const = 0;
        virtual const std::string &getUsername() const = 0;
        virtual void setUsername(const std::string &) = 0;
        virtual bool isLoggedIn() const = 0;
        virtual void setLoggedIn(bool loggedIn) = 0;
        virtual void tcpClientHasData() const = 0;
    };
} // namespace Babel::Server

#endif /* !IUSER_HPP_ */
