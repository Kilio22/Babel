/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** BabelClient
*/

#ifndef BABELCLIENT_HPP_
#define BABELCLIENT_HPP_

#include "IClient.hpp"
#include <string>

namespace Babel::Client
{
    class BabelClient : public IClient {
        public:
            BabelClient() = default;
            ~BabelClient() = default;

            void create(int ac, char *av[]);
        private:
            unsigned short port;
            std::string serveurIp;
            std::string clientIp;
    };
}

#endif /* !BABELCLIENT_HPP_ */
