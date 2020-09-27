/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CallWindow
*/

#ifndef CALLWINDOW_HPP_
#define CALLWINDOW_HPP_

#include <QtCore/QObject>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include "gui/PersonMainWidget.hpp"
#include <QtWidgets/QVBoxLayout>
#include <vector>
#include <memory>

namespace Babel::Client::Gui {
    class CallWindow : public QMainWindow
    {
        Q_OBJECT
        private:
            QScrollArea area;
            QWidget widget;
            QLabel avatar;
            QLabel myName;
            QVBoxLayout vLayout;
            QPushButton callBtn;
            QLabel errorStr;
            std::string username;
            std::vector<std::unique_ptr<PersonMainWidget>> callList;

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
            CallWindow(QWidget *parent = nullptr);
            ~CallWindow() = default;

            void setUsername(const std::string &name);
            void setError(const std::string &error);
            void setCallList(const std::vector<std::string> &nameList);

        private slots:
            void EndCallClicked();
    };
}

#endif /* !CALLWINDOW_HPP_ */
