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
#include "BabelClient.hpp"
#include <iostream>
#include "exceptions.h"
#include "WindowManager.hpp"
#include "ServiceLocator.hpp"
#include "AudioManager.hpp"

int main(int ac, char **av)
{
    try {
        QApplication app (ac, av);
        // Babel::Audio::AudioManager mnger;
        Babel::Client::BabelClient babelClient(ac, av);
        // mnger.startListening();
        // mnger.stopListening();
        babelClient.connect();
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

// Username : entre 3 et 32 char
// Password : entre 3 et 42 char