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

#include "gui/LoginWindow.hpp"
#include "gui/SignupWindow.hpp"
#include "gui/MainWindow.hpp"
#include "gui/CallWindow.hpp"
#include "ContactTimer.hpp"

namespace Babel::Client {
    /**
     * @brief This class is used to managed all the windows and their interactions.
     * 
     */
    class WindowManager {
        public:
                WindowManager();
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

        private:
            WindowManager::State state;
            //std::unique_ptr<QMainWindow> loginWindow;
            std::vector<std::unique_ptr<QMainWindow>> windows;
            ContactTimer contactTimer;
    };
};

#endif /* !WINDOWMANAGER_HPP_ */