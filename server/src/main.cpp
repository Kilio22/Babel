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
    if (ac >= 2 && std::string(av[1]) == "-h") {
        std::cout << "USAGE: ./babel_server <port>" << std::endl;
        std::cout << "port: unsigned number between 1024 and 65 535" << std::endl;
        return 0;
    }
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
