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

        void setSqlResults(int argc, char **argv);

        void addUser(const std::string &username, const std::string &password) final;
        const std::vector<std::string> &getUserLogs(const std::string &username) final;
        const std::vector<std::string> &getUserContacts(const std::string &username) final;
        void addContact(const std::string &username, const std::string &contact_username) final;

        static int callback(void *NotUsed, int argc, char **argv, char **azColName);

    private:
        SqlDb();
        SqlDb(const SqlDb &) = delete;
        SqlDb &operator=(const SqlDb &) = delete;

        static SqlDb sqlDbInstance;
        sqlite3 *db;
        std::vector<std::string> queryResults;
    };
} // namespace Babel::Server

#endif /* !SQLDB_HPP_ */
