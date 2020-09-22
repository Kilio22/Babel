/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** WindowManager
*/

#include "WindowManager.hpp"
#include "gui/LoginWindow.hpp"

Babel::Client::WindowManager::WindowManager()
: state(Babel::Client::WindowManager::State::Login)
, windows(int(State::LastEnum))
{
    // On est obligé de les initialiser comme ça.
    // Avec le Make Unique on appelle le constructeur de QMainWindow directement sinon.
    for (int i = int(State::Signup); i < int(State::LastEnum); i++) {
        windows[i].reset(new Gui::LoginWindow());
    }
    //windows[int(State::Login)].reset(new Gui::LoginWindow());
    windows[int(state)]->show();
    std::cout << "mdr" << std::endl;
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
    windows[int(state)]->show();
    this->state = state;
    std::cout << "lol" << std::endl;
}

const Babel::Client::WindowManager::State &Babel::Client::WindowManager::getState() const
{
    return (state);
}