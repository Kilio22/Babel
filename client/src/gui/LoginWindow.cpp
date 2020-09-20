/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginWindow
*/

#include "LoginWindow.hpp"

#include <QtGui/QScreen>
#include <QtGui/QGuiApplication>
#include <QtGui/QPixmap>

Babel::Client::Gui::LoginWindow::LoginWindow(QWidget *parent) 
: QMainWindow(parent)
, loginBtn("S'inscrire", this)
, logo(this)
, username(this)
, password(this)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    QPixmap pm("./assets/Babybel.png");

    this->setStyleSheet("background-color: white;");
    this->setFixedSize(640, 800);
    this->move(screenGeometry.width() / 2 - this->width() / 2, screenGeometry.height() / 2 - this->height() / 2);

    logo.setPixmap(pm);
    logo.setScaledContents(true);
    logo.resize(484, 200);
    logo.move(this->width() / 2 - logo.width() / 2, 50);

    loginBtn.setFixedSize(350, 70);
    loginBtn.setStyleSheet( "background-color: #3b3b3b;"
                            "color: white;"
                            "border-radius: 25;"
                            "selection-background-color: #636363;"
                            "font-size: 20px;");
    loginBtn.move(this->width() / 2 - loginBtn.width()  / 2, 650);

    username.setFixedSize(350, 64);
    username.move(this->width() / 2 - username.width() / 2, 350);
    username.setLineWrapMode(QTextEdit::LineWrapMode::NoWrap);
    username.setStyleSheet( "border-radius: 24;"
                            "font-size: 20px;"
                            "padding: 12px;"
                            "border: 2px solid black;");

    password.setFixedSize(350, 64);
    password.move(this->width() / 2 - password.width() / 2, 450);
    password.setLineWrapMode(QTextEdit::LineWrapMode::NoWrap);
    password.setStyleSheet( "border-radius: 24;"
                            "font-size: 20px;"
                            "padding: 12px;"
                            "border: 2px solid black;");

    loginBtn.show();
    logo.show();
    username.show();
    password.show();

    QObject::connect(&this->loginBtn, SIGNAL (pressed()), this, SLOT (print()));
}

void Babel::Client::Gui::LoginWindow::print() {
    std::cout << "Username : " << username.toPlainText().toStdString() << std::endl;
    std::cout << "Password : " << password.toPlainText().toStdString() << std::endl;
}

#include "moc_LoginWindow.cpp"