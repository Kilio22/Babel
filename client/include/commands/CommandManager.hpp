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
#include <QtCore/QObject>
#include <cstring>

namespace Babel::Client
{
    class CommandManager : public QObject {
        Q_OBJECT
    public:
        CommandManager();
        ~CommandManager() = default;

        void create(const std::string &serveurIp, unsigned short port, const std::string &clientIp);
        bool connect();
        void signup(const std::string &username, const std::string &password);
        void login(const std::string &username, const std::string &password);
        void addContact(const std::string &username);
        void getContacts();
        void startCall(std::vector<std::string>);
        void stopCall();
        void disconnect();

    private:
        unsigned short port;
        std::string serveurIp;
        std::string clientIp;
        std::unique_ptr<Network::ITcpClient> tcpClient;
    private slots:
        void onDataAvailable();
    };

    namespace Commands
    {
        const std::size_t USERNAME_LENGTH = 33;
        const std::size_t PASSWORD_LENGTH = 43;
        const std::size_t IP_LENGTH = 16;
#pragma pack(push, 1) // to remove padding to avoid problem with different compilers and with network transfer.

        struct LoginRequest
        {
            Header header;
            char username[USERNAME_LENGTH];
            char password[PASSWORD_LENGTH];
            char ip[IP_LENGTH];
        };

        struct ClassicResponse
        {
            Header header;
            enum RESPONSE_CODE responseCode;
        };

        struct RegisterRequest
        {
            Header header;
            char username[USERNAME_LENGTH];
            char password[PASSWORD_LENGTH];
        };

        struct Contact
        {
            Contact(const char *username, bool loggedIn)
                : loggedIn(loggedIn)
            {
                std::strncpy(this->username, username, USERNAME_LENGTH);
            }
            char username[USERNAME_LENGTH];
            bool loggedIn;
        };

        struct Username
        {
            Username(const std::string &username)
            {
                std::strncpy(this->username, username.c_str(), USERNAME_LENGTH);
            }
            char username[USERNAME_LENGTH];
        };

        struct AddContactRequest
        {
            Header header;
            char username[USERNAME_LENGTH];
        };

        struct UserCallInfos
        {
            UserCallInfos(const char *username, const char *ip)
            {
                std::strncpy(this->username, username, USERNAME_LENGTH);
                std::strncpy(this->ip, ip, IP_LENGTH);
            }
            char username[USERNAME_LENGTH];
            char ip[IP_LENGTH];
        };

        struct StartCallRequest
        {
            Header header;
        };

        struct StopCallRequest
        {
            Header header;
        };

#pragma pack(pop)
    } // namespace Commands
}

#endif /* !COMMANDMANAGER_HPP_ */
