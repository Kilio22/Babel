/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** WindowManager
*/

#include "WindowManager.hpp"
#include <iostream>

Babel::Client::WindowManager::WindowManager()
: state(Babel::Client::WindowManager::State::Signup)
, windows(int(State::LastEnum))
, contactTimer()
{
    // On est obligé de les initialiser avec reset.
    // Avec le Make Unique on appelle le constructeur de QMainWindow directement sinon.
    windows[int(State::Login)] = std::make_unique<Gui::LoginWindow>();
    windows[int(State::Signup)] = std::make_unique<Gui::SignupWindow>();
    windows[int(State::Main)] = std::make_unique<Gui::MainWindow>();
    windows[int(State::Call)] = std::make_unique<Gui::CallWindow>();
    windows[int(state)]->show();
    aboutPopUp.reset(nullptr);

}

Babel::Client::WindowManager::~WindowManager()
{
    for (int i = int(State::Signup); i < int(State::LastEnum); i++) {
        windows[i].release();
    }
}

void Babel::Client::WindowManager::setState(const Babel::Client::WindowManager::State &state)
{
    if (state == this->state || state == State::LastEnum)
        return;
    for (int i = int(State::Signup); i < int(State::LastEnum); i++) {
        windows[i]->hide();
    }
    this->state = state;
    windows[int(state)]->show();
}

const Babel::Client::WindowManager::State &Babel::Client::WindowManager::getState() const
{
    return (state);
}

Babel::Client::Gui::LoginWindow *Babel::Client::WindowManager::getLoginWindow() const
{
    if (Babel::Client::Gui::LoginWindow* c = dynamic_cast<Babel::Client::Gui::LoginWindow*>(windows[int(State::Login)].get()))
    {
        return (c);
    }
    return (nullptr);
}

Babel::Client::Gui::SignupWindow *Babel::Client::WindowManager::getSignupWindow() const
{
    if (Babel::Client::Gui::SignupWindow* c = dynamic_cast<Babel::Client::Gui::SignupWindow*>(windows[int(State::Signup)].get()))
    {
        return (c);
    }
    return (nullptr);
}

Babel::Client::Gui::MainWindow *Babel::Client::WindowManager::getMainWindow() const
{
    if (Babel::Client::Gui::MainWindow* c = dynamic_cast<Babel::Client::Gui::MainWindow*>(windows[int(State::Main)].get()))
    {
        return (c);
    }
    return (nullptr);
}

Babel::Client::Gui::CallWindow *Babel::Client::WindowManager::getCallWindow() const
{
    if (Babel::Client::Gui::CallWindow* c = dynamic_cast<Babel::Client::Gui::CallWindow*>(windows[int(State::Call)].get()))
    {
        return (c);
    }
    return (nullptr);
}

void Babel::Client::WindowManager::openAbout()
{
    aboutPopUp = std::make_unique<Gui::AboutWindow>();
}