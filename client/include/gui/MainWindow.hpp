/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** MainWindow
*/

#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QtCore/QObject>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include "gui/PersonMainWidget.hpp"
#include <QtWidgets/QVBoxLayout>


#include <iostream>

namespace Babel::Client::Gui {
    /**
     * @brief This class represents the login window. It inherits from QMainWindow.
     * 
     */
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
        private:
            QScrollArea area;
            QWidget widget;
            QLabel avatar;
            QLabel myName;
            QLineEdit contactLine;
            QPushButton contactBtn;
            QVBoxLayout vLayout;
            QPushButton callBtn;
            QLabel errorStr;
            std::string username;
            std::vector<std::unique_ptr<PersonMainWidget>> contacts;

            /**
             * @brief Reset the state of the window.
             * 
             */
            void reset();

        public:
            /**
             * @brief Construct a new Login Window object
             * 
             * @param parent Parent of the widget.
             */
            MainWindow(QWidget *parent = nullptr);
            ~MainWindow() = default;

            void setUsername(const std::string &name);
            void setError(const std::string &error);
            const std::vector<std::string> getUsersCalled() const;

        private slots:
            void setContacts(const std::vector<std::string> &nameList);
            void addContact();
            void callClicked();
    };
};

#endif /* !MAINWINDOW_HPP_ */
