/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginWindow
*/

#ifndef LOGINWINDOW_HPP_
#define LOGINWINDOW_HPP_

#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtGui/QMovie>

namespace Babel::Client::Gui {
    class LoginWindow : public QWidget
    {
        Q_OBJECT
        private:
            QWidget mainWidget;
            QLabel logo;
            QPushButton loginBtn;
            QLineEdit username;
            QLineEdit password;
            QPushButton signupBtn;
            QLabel bottomText;
            QLabel topText;
            QLabel loaderGif;
            QMovie movie; 
            std::string lastUsername;

            /**
             * @brief Evalute if the inputs in the form are valid.
             * 
             */
            void evaluateForms();
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
            LoginWindow(QWidget *parent = nullptr);
            ~LoginWindow() = default;

            void setError(const std::string &errorStr);
            void loginWorked();

        private slots:
            /**
             * @brief Submit the login form and evaluate it.
             * 
             */
            void submitLogin();
            /**
             * @brief Switch to the Sign Up Window.
             * 
             */
            void switchToSignup();
    };
};

#endif /* !LOGINWINDOW_HPP_ */
