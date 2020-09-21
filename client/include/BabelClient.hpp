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
            BabelClient(int ac, const char *av[]);
            ~BabelClient() = default;

            void run() final;
        private:
            unsigned short port;
            std::string ip;
    };
}

#endif /* !BABELCLIENT_HPP_ */
