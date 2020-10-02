/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** SqlDb
*/

#ifndef SQLDB_HPP_
#define SQLDB_HPP_

#include "database/IDb.hpp"
#include <sqlite3.h>

namespace Babel::Server
{
    class SqlDb : public IDb {
    public:
        SqlDb();
        ~SqlDb();

        bool hasUser(const std::string &username) const final;
        void addUser(const std::string &username, const std::string &password) const final;
        std::vector<std::string> getUserLogs(const std::string &username) const final;
        std::vector<Username> getUserContacts(const std::string &username) const final;
        void addContact(const std::string &username, const std::string &contact_username) const final;

        static int callback(void *, int argc, char **argv, char **);
        static int contactCallback(void *, int argc, char **argv, char **);

    private:
        sqlite3 *m_db;
    };
} // namespace Babel::Server

#endif /* !SQLDB_HPP_ */
