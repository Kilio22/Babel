/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IDb
*/

#ifndef IDB_HPP_
#define IDB_HPP_

#include <cstring>
#include <string>
#include <vector>

namespace Babel::Server
{
#pragma pack(push, 1)

    struct Username
    {
        Username(const std::string &username)
        {
            std::strncpy(this->username, username.c_str(), 33);
        }
        char username[33];
    };

#pragma pack(pop)

    class IDb {
    public:
        virtual ~IDb() = default;

        virtual void addUser(const std::string &username, const std::string &password) = 0;
        virtual const std::vector<std::string> &getUserLogs(const std::string &username) = 0;
        virtual const std::vector<Username> &getUserContacts(const std::string &username) = 0;
        virtual void addContact(const std::string &username, const std::string &contact_username) = 0;
    };
} // namespace Babel::Server

#endif /* !IDB_HPP_ */
