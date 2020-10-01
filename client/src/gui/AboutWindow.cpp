/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AboutWindow
*/

#include "AboutWindow.hpp"

#include <iostream>
#include <QtGui/QScreen>
#include <QtGui/QGuiApplication>
#include <QtGui/QPixmap>
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"

Babel::Client::Gui::AboutWindow::AboutWindow(QWidget *parent)
: QMainWindow(parent)
, textLabel(this)
, logoLabel(this)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    QPixmap pm("./assets/Babybel.png");

    this->setWindowTitle("À propos");
    this->setStyleSheet("background-color: white;");
    this->setFixedSize(320, 320);
    this->move(screenGeometry.width() / 2 - this->width() / 2, screenGeometry.height() / 2 - this->height() / 2);
    this->setWindowIcon(QIcon("./assets/logo.jpg"));

    logoLabel.setPixmap(pm);
    logoLabel.setScaledContents(true);
    logoLabel.resize(242, 100);
    logoLabel.move(this->width() / 2 - logoLabel.width() / 2, 25);

    textLabel.setFixedSize(320, 220);
    textLabel.move(this->width() / 2 - textLabel.width() / 2, 125);
    textLabel.setAlignment(Qt::AlignCenter);
    textLabel.setText("Babel Epitech Project\n\nFait par :\nAntoine GOSSELIN\nGhassane SEBAÏ\nKylian BALAN\nNathan LECORCHET\n\nVersion qqchose. On sait pas enft.");
    textLabel.setStyleSheet(   "color: black;"
                                "font-size: 14px;");

    this->show();
    logoLabel.show();
    textLabel.show();
}