/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginWindow
*/

#ifndef LOGINWINDOW_HPP_
#define LOGINWINDOW_HPP_

#include <QtCore/QObject>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>
#include <iostream>

namespace Babel::Client::Gui {

    class LoginWindow : public QMainWindow
    {
        Q_OBJECT
        private:
            QLabel logo;
            QPushButton loginBtn;
            QTextEdit username;
            QTextEdit password;

        public:
            explicit LoginWindow(QWidget *parent = nullptr);
            ~LoginWindow() = default;

        private slots:
            void print();
    };
};

#endif /* !LOGINWINDOW_HPP_ */
