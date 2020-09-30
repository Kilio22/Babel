/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AboutWindow
*/

#ifndef ABOUTWINDOW_HPP_
#define ABOUTWINDOW_HPP_

#include <QtCore/QObject>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>

namespace Babel::Client::Gui {
    class AboutWindow : public QMainWindow {
        public:
            AboutWindow(QWidget *parent = nullptr);
            ~AboutWindow() = default;

        protected:
        private:
            QLabel textLabel;
            QLabel logoLabel;

    };
};

#endif /* !ABOUTWINDOW_HPP_ */
