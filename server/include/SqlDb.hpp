/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** SqlDb
*/

#ifndef SQLDB_HPP_
#define SQLDB_HPP_

#include "IDb.hpp"
#include <sqlite3.h>

namespace Babel::Server
{
    class SqlDb : public IDb {
    public:
        ~SqlDb();

        static SqlDb &getInstance();

        void addUser(const std::string &username, const std::string &password) final;

    private:
        SqlDb();
        SqlDb(const SqlDb &) = delete;
        SqlDb &operator=(const SqlDb &) = delete;

        static SqlDb sqlDbInstance;
        sqlite3 *db;
    };
} // namespace Babel::Server

#endif /* !SQLDB_HPP_ */
