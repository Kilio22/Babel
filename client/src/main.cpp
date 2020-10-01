/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** main
*/

#include "BabelClient.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include "ClientException.hpp"
#include <QtWidgets/QApplication>
#include <iostream>

int main(int ac, char **av)
{
    try {
        QApplication app(ac, av);
        Babel::Client::ServiceLocator::getInstance().get<Babel::Client::BabelClient>().create(ac, av);

        app.exec();
    } catch (const Babel::Client::Exceptions::ClientException &e) {
        std::cerr << e.getComponent() << ": " << e.what() << std::endl;
        return 84;
    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: '" << e.what() << "'" << std::endl;
        return 84;
    }
    return 0;
}
