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
#include "CommandManager.hpp"
#include <vector>
#include <memory>
#include <unordered_map>

namespace Babel::Client::Gui {
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
            QPushButton disconnectBtn;
            QPushButton aboutBtn;
            std::vector<std::unique_ptr<PersonMainWidget>> contacts;
            std::unordered_map<std::string, bool> saveContacts;

            /**
             * @brief Reset the state of the window.
             *
             */
            void reset();

        public:
            MainWindow(QWidget *parent = nullptr);
            ~MainWindow() = default;

            void setUsername(const std::string &name);
            void setError(const std::string &error);
            const std::vector<std::string> getUsersCalled() const;
            void setContacts(const std::vector<Babel::Client::Commands::Contact> &contacts);
            void callWorked(const std::vector<Babel::Client::Commands::UserCallInfos> &userInfo);
            void disconnectWorked() const;

        private slots:
            void addContact();
            void callClicked();
            void disconnect() const;
            void openAbout() const;
    };
};

#endif /* !MAINWINDOW_HPP_ */
