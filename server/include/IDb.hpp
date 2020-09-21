/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IDb
*/

#ifndef IDB_HPP_
#define IDB_HPP_

#include <string>

namespace Babel::Server
{
    class IDb {
    public:
        virtual ~IDb() = default;

        virtual void addUser(const std::string &username, const std::string &password) = 0;
    };
} // namespace Babel::Server

#endif /* !IDB_HPP_ */
