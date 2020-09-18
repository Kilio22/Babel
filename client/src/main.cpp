/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <opus.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

int main(int ac, char **av)
{
    std::map<int, int> mymap = {{1, 1}, {2, 2}};
    QApplication app (ac, av);
    QMainWindow window;
    QPushButton btn(&window);
    QObject michel;

    btn.setText("M dr c un bouton");
    window.show();
    btn.show();
    window.setWindowTitle("Jean Michel");
    std::cout << "hello, world!" << std::endl;
    app.exec();
    return mymap.contains(1);
}
