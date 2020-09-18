/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** main
*/

// Faut move tout ça après aussi ...
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>
#include <opus.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

#include "exceptions.h"

int main(int ac, char ** av)
{
    try {
        // Le programme ici haha
    } catch (const Babel::Exceptions::ClientException &e) {
        std::cerr << e.getComponent() << ": " << e.what() << std::endl;
        return 84;
    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: '" << e.what() << "'" << std::endl;
        return 84;
    }
    return 0;
}

// Username : entre 3 et 120 char
// Password : entre 3 et 120 char

// int main(int ac, char **av)
// {
//     std::map<int, int> mymap = {{1, 1}, {2, 2}};
//     QApplication app (ac, av);
//     QMainWindow window;
//     QPushButton btn(&window);
//     QObject michel;

//     btn.setText("M dr c un bouton");
//     window.show();
//     btn.show();
//     window.setWindowTitle("Jean Michel");
//     std::cout << "hello, world!" << std::endl;
//     app.exec();
//     return mymap.contains(1);
// }