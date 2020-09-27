/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CommandManager
*/

#ifndef COMMANDMANAGER_HPP_
#define COMMANDMANAGER_HPP_

#include "CommandParser.hpp"
#include "ITcpClient.hpp"
#include <cstring>

namespace Babel::Client
{
    class CommandManager {
    public:
        CommandManager();
        ~CommandManager() = default;

        void create(const std::string &ip, unsigned short port, Network::ITcpClient *tcpClient);
        bool connect();
        void signup(const std::string &username, const std::string &password);
        void login(const std::string &username, const std::string &password);
        void addContact(const std::string &username);
        void getContacts();

    private:
        unsigned short port;
        std::string ip;
        Network::ITcpClient *tcpClient;
    };

    namespace Commands
    {
#pragma pack(push, 1) // to remove padding to avoid problem with different compilers and with network transfer.

        struct LoginRequest
        {
            Header header;
            char username[33];
            char password[43];
        };

        struct LoginResponse
        {
            Header header;
            enum RESPONSE_CODE responseCode;
        };

        struct RegisterRequest
        {
            Header header;
            char username[33];
            char password[43];
        };

        struct RegisterResponse
        {
            Header header;
            enum RESPONSE_CODE responseCode;
        };

        struct Contact
        {
            Contact(const char *username, bool loggedIn)
                : loggedIn(loggedIn)
            {
                std::strncpy(this->username, username, 33);
            }
            char username[33];
            bool loggedIn;
        };

        struct AddContactRequest
        {
            Header header;
            char username[33];
        };

        struct AddContactsResponse
        {
            Header header;
            enum RESPONSE_CODE responseCode;
        };

        struct GetContactsResponse
        {
            Header header;
            enum RESPONSE_CODE responseCode;
        };

#pragma pack(pop)
    } // namespace Commands
}

#endif /* !COMMANDMANAGER_HPP_ */
