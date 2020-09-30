/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** SignupWindow
*/

#ifndef SIGNUPWINDOW_HPP_
#define SIGNUPWINDOW_HPP_

#include <QtCore/QObject>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtGui/QMovie>

namespace Babel::Client::Gui {
    class SignupWindow : public QMainWindow
    {
        Q_OBJECT
        private:
            QWidget mainWidget;
            QLabel logo;
            QPushButton submitBtn;
            QLineEdit username;
            QLineEdit password;
            QPushButton loginBtn;
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
             * @brief Construct a new Sign Up Window object
             * 
             * @param parent Parent of the widget.
             */
            SignupWindow(QWidget *parent = nullptr);
            ~SignupWindow() = default;

            void setError(const std::string &errorStr);
            void signupWorked();

        private slots:
            /**
             * @brief Submit the login form and evaluate it.
             * 
             */
            void submitSignup();
            /**
             * @brief Switch to the Login Window.
             * 
             */
            void switchToLogin();
    };
};

#endif /* !SIGNUPWINDOW_HPP_ */
