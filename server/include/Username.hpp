/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** Username
*/

#ifndef USERNAME_HPP_
#define USERNAME_HPP_

#include <cstring>
#include <string>

namespace Babel::Server
{
    const std::size_t USERNAME_LENGTH = 33;

#pragma pack(push, 1)
    struct Username
    {
        Username(const std::string &username)
        {
            std::strncpy(this->username, username.c_str(), USERNAME_LENGTH);
        }
        char username[USERNAME_LENGTH];
    };
#pragma pack(pop)

} // namespace Babel::Server

#endif /* !USERNAME_HPP_ */
