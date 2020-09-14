//
// EPITECH PROJECT, 2018
// babel
// File description:
// babel
//

#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <opus/opus.h>
#include <portaudio.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QPushButton button("Hello world !");

    button.show();
    return app.exec();
}
