/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IDb
*/

#ifndef IDB_HPP_
#define IDB_HPP_

#include "Username.hpp"
#include <vector>

namespace Babel::Server
{
    class IDb {
    public:
        virtual ~IDb() = default;

        virtual bool hasUser(const std::string &username) const = 0;
        virtual void addUser(const std::string &username, const std::string &password) const = 0;
        virtual std::vector<std::string> getUserLogs(const std::string &username) const = 0;
        virtual std::vector<Username> getUserContacts(const std::string &username) const = 0;
        virtual void addContact(const std::string &username, const std::string &contact_username) const = 0;
    };
} // namespace Babel::Server

#endif /* !IDB_HPP_ */
