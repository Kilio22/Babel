/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** StopCallCommand
*/

#include "commands/StopCallCommand.hpp"
#include "UserManager.hpp"

void Babel::Server::Commands::StopCallCommand::handle(const unsigned char *, std::size_t, Babel::Server::IUser *user) const
{
    StopCallResponse stopCallResponse = { { COMMAND_TYPE::STOP_CALL }, STOP_CALL_RESPONSE_CODE::OK };
    if (!user->isLoggedIn()) {
        stopCallResponse.responseCode = STOP_CALL_RESPONSE_CODE::NOT_LOGGED_IN;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&stopCallResponse), sizeof(StopCallResponse));
    }
    if (user->isInCall() == false) {
        stopCallResponse.responseCode = STOP_CALL_RESPONSE_CODE::NOT_IN_CALL;
        return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&stopCallResponse), sizeof(StopCallResponse));
    }

    const std::vector<std::string> &calledUsernames = user->getCalledUsers();
    for (const auto &calledUsername : calledUsernames) {
        IUser *calledUser = UserManager::getInstance().getUserByUsername(calledUsername);

        if (calledUser == nullptr) {
            continue;
        }
        calledUser->setInCall(false);
        calledUser->setCalledUsers({});
        calledUser->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&stopCallResponse), sizeof(StopCallResponse));
    }
    user->setInCall(false);
    user->setCalledUsers({});
    return user->getTcpClient()->write(reinterpret_cast<const unsigned char *>(&stopCallResponse), sizeof(StopCallResponse));
}
