/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** WindowManager
*/

#ifndef WINDOWMANAGER_HPP_
#define WINDOWMANAGER_HPP_

#include <QtWidgets/QMainWindow>
#include <vector>
#include <memory>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include "gui/LoginWindow.hpp"
#include "gui/SignupWindow.hpp"
#include "gui/MainWindow.hpp"
#include "gui/CallWindow.hpp"
#include "gui/AboutWindow.hpp"
#include "ContactTimer.hpp"

namespace Babel::Client::Gui
{
    /**
     * @brief This class is used to managed all the windows and their interactions.
     *
     */
    class WindowManager {
    public:
        WindowManager(int argc = 0, char **argv = nullptr);
        ~WindowManager();

        enum class State : int {
            Signup,
            Login,
            Main,
            Call,
            LastEnum
        };

        /**
         * @brief Set the State object
         *
         * @param state State of the manager (Which window should be displayed)
         */
        void setState(const WindowManager::State &state);
        /**
         * @brief Get the State object
         *
         * @return const WindowManager::State&
         */
        const WindowManager::State &getState() const;
        Babel::Client::Gui::LoginWindow *getLoginWindow() const;
        Babel::Client::Gui::SignupWindow *getSignupWindow() const;
        Babel::Client::Gui::MainWindow *getMainWindow() const;
        Babel::Client::Gui::CallWindow *getCallWindow() const;
        void openAbout();

    private:
        WindowManager::State state;
        std::vector<std::unique_ptr<QWidget>> widgets;
        std::vector<std::string> windowNames;
        ContactTimer contactTimer;
        QMainWindow appWindow;
        std::unique_ptr<Babel::Client::Gui::AboutWindow> aboutPopUp;
    };
};

#endif /* !WINDOWMANAGER_HPP_ */
