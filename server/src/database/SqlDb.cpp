/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** SqlDb
*/

#include "database/SqlDb.hpp"
#include "database/DatabaseProvider.hpp"
#include "exceptions/ConstraintDatabaseException.hpp"
#include "exceptions/CreateTableException.hpp"
#include "exceptions/OpenDatabaseException.hpp"
#include "exceptions/QueryDatabaseException.hpp"
#include <cstring>
#include <iostream>

Babel::Server::SqlDb::SqlDb()
    : m_db(nullptr)
{
    int rc = sqlite3_open("babel_dev.db", &this->m_db);
    char *errorMessage = nullptr;

    if (rc) {
        sqlite3_close(this->m_db);
        throw Exceptions::OpenDatabaseException("Can't open database: " + std::string(sqlite3_errmsg(m_db)), "Babel::Server::SqlDb::SqlDb");
    }
    rc = sqlite3_exec(m_db, "CREATE TABLE IF NOT EXISTS users(username TEXT PRIMARY KEY, password TEXT);", nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::OpenDatabaseException("Can't create table \"users\": " + std::string(errorMessage), "Babel::Server::SqlDb::SqlDb");
    }
    rc = sqlite3_exec(m_db, "CREATE TABLE IF NOT EXISTS users_contacts(username TEXT, contact_username TEXT);", nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::OpenDatabaseException("Can't create table \"users_contacts\": " + std::string(errorMessage), "Babel::Server::SqlDb::SqlDb");
    }
}

Babel::Server::SqlDb::~SqlDb()
{
    sqlite3_close(this->m_db);
}

bool Babel::Server::SqlDb::hasUser(const std::string &username) const
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "SELECT username FROM users WHERE username=\"" + username + "\";";
    std::vector<std::string> queryResults;

    rc = sqlite3_exec(m_db, query.c_str(), SqlDb::callback, &queryResults, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't get user logs: " + std::string(errorMessage), "Babel::Server::SqlDb::getUserLogs");
    }
    return !queryResults.empty();
}

void Babel::Server::SqlDb::addUser(const std::string &username, const std::string &password) const
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "INSERT INTO users VALUES (\"" + username + "\", \"" + password + "\");";

    rc = sqlite3_exec(m_db, query.c_str(), nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK && rc == SQLITE_CONSTRAINT) {
        throw Exceptions::ConstraintDatabaseException("Can't insert new user : " + std::string(errorMessage), "Babel::Server::SqlDb::addUser");
    } else if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't insert new user : " + std::string(errorMessage), "Babel::Server::SqlDb::addUser");
    }
}

std::vector<std::string> Babel::Server::SqlDb::getUserLogs(const std::string &username) const
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "SELECT username, password FROM users WHERE username=\"" + username + "\";";
    std::vector<std::string> queryResults;

    rc = sqlite3_exec(m_db, query.c_str(), SqlDb::callback, &queryResults, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't get user logs: " + std::string(errorMessage), "Babel::Server::SqlDb::getUserLogs");
    }
    return queryResults;
}

std::vector<Babel::Server::Username> Babel::Server::SqlDb::getUserContacts(const std::string &username) const
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "SELECT contact_username FROM users_contacts WHERE users_contacts.username=\"" + username + "\";";
    std::vector<Username> queryResults;

    rc = sqlite3_exec(m_db, query.c_str(), SqlDb::contactCallback, &queryResults, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't get user contacts: " + std::string(errorMessage), "Babel::Server::SqlDb::getUserContacts");
    }
    return queryResults;
}

void Babel::Server::SqlDb::addContact(const std::string &username, const std::string &contactUsername) const
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "INSERT INTO users_contacts(username,contact_username) SELECT \"" + username + "\", \"" + contactUsername
        + "\" WHERE NOT EXISTS(SELECT 1 FROM users_contacts WHERE username=\"" + username + "\" AND contact_username=\"" + contactUsername + "\");";

    rc = sqlite3_exec(m_db, query.c_str(), nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't get insert new contact: " + std::string(errorMessage), "Babel::Server::SqlDb::addContact");
    }
}

int Babel::Server::SqlDb::callback(void *data, int argc, char **argv, char **)
{
    auto *queryResults = reinterpret_cast<std::vector<std::string> *>(data);

    for (std::size_t i = 0; i < argc; i++) {
        queryResults->push_back(argv[i]);
    }
    return 0;
}

int Babel::Server::SqlDb::contactCallback(void *data, int argc, char **argv, char **)
{
    auto *queryResults = reinterpret_cast<std::vector<Username> *>(data);

    for (std::size_t i = 0; i < argc; i++) {
        queryResults->push_back({ argv[i] });
    }
    return 0;
}
