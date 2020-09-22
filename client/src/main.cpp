/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** main
*/

// Faut move tout ça après aussi ...
#include <QtWidgets/QApplication>
#include <opus.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

#include "exceptions.h"
#include "WindowManager.hpp"
#include "ServiceLocator.hpp"

int main(int ac, char ** av)
{
    try {
        QApplication app (ac, av);
        Babel::Client::ServiceLocator::getInstance().get<Babel::Client::WindowManager>().setState(Babel::Client::WindowManager::State::Login);
        //Babel::Client::WindowManager manager;
        //Babel::Client::Gui::LoginWindow window;

        //window.show();
        //window.setWindowTitle("Babybel");
        app.exec();
    } catch (const Babel::Exceptions::ClientException &e) {
        std::cerr << e.getComponent() << ": " << e.what() << std::endl;
        return 84;
    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: '" << e.what() << "'" << std::endl;
        return 84;
    }
    return 0;
}

// Username : entre 3 et 32 char
// Password : entre 3 et 42 char