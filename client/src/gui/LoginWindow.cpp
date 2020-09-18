/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginWindow
*/

#include "LoginWindow.hpp"

Babel::Client::Gui::LoginWindow::LoginWindow(QWidget *parent) 
: QMainWindow(parent)
, loginBtn("Test moi, je print mdr", this)
, testLabel(this)
{
    loginBtn.setFixedSize(400, 100);
    QObject::connect(&this->loginBtn, SIGNAL (pressed()), this, SLOT (print_mdr()));
    loginBtn.show();
}

void Babel::Client::Gui::LoginWindow::print_mdr() {
    std::cout << "mdr" << std::endl;
}

#include "moc_LoginWindow.cpp"