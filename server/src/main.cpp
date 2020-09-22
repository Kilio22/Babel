/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** main
*/

#include "BabelServer.hpp"
#include "exceptions/BabelServerException.hpp"
#include <iostream>

int main(int ac, const char *av[])
{
    try {
        Babel::Server::BabelServer babelServer(ac, av);

        babelServer.run();
    } catch (Babel::Server::Exceptions::BabelServerException &e) {
        std::cerr << e.where() << ": " << e.what() << std::endl;
        return 84;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}