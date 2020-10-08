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
#include <cstring>

int main(int ac, char **av)
{
    try {
        QApplication qApplication(ac, av);

        if (ac == 2 && strcmp("-h", av[1]) == 0) {
            std::cout << av[0] << ": serverIp port clientIp" << std::endl;
            std::cout << "    serverIp : ip of the Babel server" << std::endl;
            std::cout << "    port     : port of the Babel server" << std::endl;
            std::cout << "    clientIp : ip of the client you are starting" << std::endl;
            return 0;
        }
        Babel::Client::ServiceLocator::getInstance().get<Babel::Client::BabelClient>().create(ac, av);
        Babel::Client::ServiceLocator::getInstance().get<Babel::Client::Gui::WindowManager>();
        qApplication.exec();
    } catch (const Babel::Client::Exceptions::ClientException &e) {
        std::cerr << e.getComponent() << ": " << e.what() << std::endl;
        return 84;
    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: '" << e.what() << "'" << std::endl;
        return 84;
    }
    return 0;
}
