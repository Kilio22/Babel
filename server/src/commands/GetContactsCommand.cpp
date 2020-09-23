/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** GetContactsCommand
*/

#include "GetContactsCommand.hpp"
#include "UserManager.hpp"

void Babel::Server::Commands::GetContactsCommand::handle(const unsigned char *, ITcpClient *tcpClient) const
{
    std::shared_ptr<Babel::Server::IUser> user = UserManager::getInstance().getUserByTcpClient(tcpClient);
    if (user == nullptr)
        return;
    if (!user->isLoggedIn()) {
    }
}
