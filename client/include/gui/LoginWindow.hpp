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

namespace Babel::Client {

    class LoginWindow : QMainWindow
    {
    private:
        /* data */
    public:
        explicit LoginWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());;
        ~LoginWindow();
    };

}

#endif /* !LOGINWINDOW_HPP_ */
