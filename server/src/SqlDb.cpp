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
#include <cstring>
#include <iostream>

Babel::Server::SqlDb Babel::Server::SqlDb::sqlDbInstance;

Babel::Server::SqlDb &Babel::Server::SqlDb::getInstance()
{
    return Babel::Server::SqlDb::sqlDbInstance;
}

Babel::Server::SqlDb::SqlDb()
    : m_db(nullptr)
{
    int rc = sqlite3_open("babel_dev.db", &this->m_db);
    char *errorMessage = nullptr;

    if (rc) {
        sqlite3_close(this->m_db);
        throw Exceptions::OpenDatabaseException("Can't open database: " + std::string(sqlite3_errmsg(m_db)), "Babel::Server::SqlDb::SqlDb");
    }
    rc = sqlite3_exec(m_db, "CREATE TABLE IF NOT EXISTS users(username TEXT PRIMARY KEY, password TEXT);", NULL, 0, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::OpenDatabaseException("Can't create table \"users\": " + std::string(errorMessage), "Babel::Server::SqlDb::SqlDb");
    }
    rc = sqlite3_exec(m_db, "CREATE TABLE IF NOT EXISTS users_contacts(username TEXT, contact_username TEXT);", NULL, 0, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::OpenDatabaseException("Can't create table \"users_contacts\": " + std::string(errorMessage), "Babel::Server::SqlDb::SqlDb");
    }
}

Babel::Server::SqlDb::~SqlDb()
{
    sqlite3_close(this->m_db);
}

void Babel::Server::SqlDb::addUser(const std::string &username, const std::string &password)
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "INSERT INTO users VALUES (\"" + username + "\", \"" + password + "\");";

    rc = sqlite3_exec(m_db, query.c_str(), NULL, 0, &errorMessage);
    if (rc != SQLITE_OK && rc == SQLITE_CONSTRAINT) {
        throw Exceptions::ConstraintDatabaseException("Can't insert new user : " + std::string(errorMessage), "Babel::Server::SqlDb::addUser");
    } else if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't insert new user : " + std::string(errorMessage), "Babel::Server::SqlDb::addUser");
    }
}

const std::vector<std::string> &Babel::Server::SqlDb::getUserLogs(const std::string &username)
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "SELECT username, password FROM users WHERE username=\"" + username + "\";";
    bool shouldClear = true;

    rc = sqlite3_exec(m_db, query.c_str(), SqlDb::callback, &shouldClear, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't get user logs: " + std::string(errorMessage), "Babel::Server::SqlDb::getUserLogs");
    }
    return this->m_queryResults;
}

const std::vector<Babel::Server::Username> &Babel::Server::SqlDb::getUserContacts(const std::string &username)
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "SELECT contact_username FROM users_contacts WHERE users_contacts.username=\"" + username + "\";";
    bool shouldClear = true;

    rc = sqlite3_exec(m_db, query.c_str(), SqlDb::contactCallback, &shouldClear, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't get user contacts: " + std::string(errorMessage), "Babel::Server::SqlDb::getUserContacts");
    }
    return this->m_contactQueryResults;
}

void Babel::Server::SqlDb::addContact(const std::string &username, const std::string &contactUsername)
{
    int rc = 0;
    char *errorMessage = nullptr;
    std::string query = "INSERT INTO users_contacts(username,contact_username) SELECT \"" + username + "\", \"" + contactUsername
        + "\" WHERE NOT EXISTS(SELECT 1 FROM users_contacts WHERE username=\"" + username + "\" AND contact_username=\"" + contactUsername + "\");";

    rc = sqlite3_exec(m_db, query.c_str(), NULL, 0, &errorMessage);
    if (rc != SQLITE_OK) {
        throw Exceptions::QueryDatabaseException("Can't get insert new contact: " + std::string(errorMessage), "Babel::Server::SqlDb::addContact");
    }
}

int Babel::Server::SqlDb::callback(void *shouldClear, int argc, char **argv, char **)
{
    sqlDbInstance.setSqlResults(argc, argv, false, reinterpret_cast<bool *>(shouldClear));
    return 0;
}

int Babel::Server::SqlDb::contactCallback(void *shouldClear, int argc, char **argv, char **oui)
{
    sqlDbInstance.setSqlResults(argc, argv, true, reinterpret_cast<bool *>(shouldClear));
    return 0;
}

void Babel::Server::SqlDb::setSqlResults(int argc, char **argv, bool isUsername, bool *shouldClear)
{
    if (isUsername) {
        if (*shouldClear) {
            this->m_contactQueryResults.clear();
            *shouldClear = false;
        }
        for (int i = 0; i < argc; i++) {
            this->m_contactQueryResults.push_back({ argv[i] });
        }
    } else {
        if (*shouldClear) {
            this->m_queryResults.clear();
            *shouldClear = false;
        }
        for (int i = 0; i < argc; i++) {
            this->m_queryResults.push_back(argv[i]);
        }
    }
}
