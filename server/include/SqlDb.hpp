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

        void setSqlResults(int argc, char **argv, bool isUsername, bool *shouldClear);

        void addUser(const std::string &username, const std::string &password) const final;
        const std::vector<std::string> &getUserLogs(const std::string &username) const final;
        const std::vector<Username> &getUserContacts(const std::string &username) const final;
        void addContact(const std::string &username, const std::string &contact_username) const final;

        static int callback(void *, int argc, char **argv, char **);
        static int contactCallback(void *, int argc, char **argv, char **);

    private:
        SqlDb();
        SqlDb(const SqlDb &) = delete;
        SqlDb &operator=(const SqlDb &) = delete;

        static SqlDb sqlDbInstance;
        sqlite3 *m_db;
        std::vector<std::string> m_queryResults;
        std::vector<Username> m_contactQueryResults;
    };
} // namespace Babel::Server

#endif /* !SQLDB_HPP_ */
