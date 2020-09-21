/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** main
*/

#include "BabelClient.hpp"
#include "BabelClientException.hpp"
#include <iostream>

int main(int ac, const char *av[])
{
    try {
        Babel::Client::BabelClient babelClient(ac, av);

        babelClient.run();
    } catch (Babel::Client::Exceptions::BabelClientException &e) {
        std::cerr << e.where() << ": " << e.what() << std::endl;
        return 84;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
