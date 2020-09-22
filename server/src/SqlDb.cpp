/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** SqlDb
*/

#include "SqlDb.hpp"
#include "exceptions/ConstraintDatabaseException.hpp"
#include "exceptions/CreateTableException.hpp"
#include "exceptions/OpenDatabaseException.hpp"
#include "exceptions/QueryDatabaseException.hpp"
#include <iostream>

Babel::Server::SqlDb Babel::Server::SqlDb::sqlDbInstance;

Babel::Server::SqlDb &Babel::Server::SqlDb::getInstance()
{
    return Babel::Server::SqlDb::sqlDbInstance;
}

Babel::Server::SqlDb::SqlDb()
    : db(nullptr)
{
    int rc = sqlite3_open("babel_dev", &this->db);
    char *errorMessage = nullptr;

    if (rc) {
        sqlite3_close(this->db);
        throw Exceptions::OpenDatabaseException("Can't open database: " + std::string(sqlite3_errmsg(db)), "Babel::Server::SqlDb::SqlDb");
    }
    rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users(username TEXT PRIMARY KEY, password TEXT);", NULL, 0, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::OpenDatabaseException("Can't create table \"users\": " + std::string(errorMessage), "Babel::Server::SqlDb::SqlDb");
    }
}

Babel::Server::SqlDb::~SqlDb()
{
    sqlite3_close(this->db);
}

void Babel::Server::SqlDb::addUser(const std::string &username, const std::string &password)
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "INSERT INTO users VALUES (\"" + username + "\", \"" + password + "\");";

    rc = sqlite3_exec(db, query.c_str(), NULL, 0, &errorMessage);
    if (rc != SQLITE_OK && rc == SQLITE_CONSTRAINT) {
        throw Exceptions::ConstraintDatabaseException("Can't insert new user : " + std::string(errorMessage), "Babel::Server::SqlDb::addUser");
    } else if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't insert new user : " + std::string(errorMessage), "Babel::Server::SqlDb::addUser");
    }
}

const char **Babel::Server::SqlDb::getUserLogs(const std::string &username)
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "SELECT username, password FROM users WHERE username=\"" + username + "\";";

    rc = sqlite3_exec(db, query.c_str(), SqlDb::callback, 0, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't get user logs: " + std::string(errorMessage), "Babel::Server::SqlDb::getUserLogs");
    }
    if (this->argc == 0) {
        return nullptr;
    }
    return const_cast<const char **>(this->argv);
}

int Babel::Server::SqlDb::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    SqlDb::getInstance().setSqlResults(argc, argv, azColName);
    return 0;
}

void Babel::Server::SqlDb::setSqlResults(int argc, char **argv, char **azColName)
{
    this->argc = argc;
    this->argv = argv;
    this->azColName = azColName;
}
