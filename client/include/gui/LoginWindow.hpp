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
#include <iostream>

namespace Babel::Client::Gui {

    class LoginWindow : public QMainWindow
    {
        Q_OBJECT
        private:
            /* data */
        public:
            explicit LoginWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags()) : QMainWindow(parent, flags) {}
            ~LoginWindow() = default;

        public slots:
            void print_mdr();
    };
};

#endif /* !LOGINWINDOW_HPP_ */
