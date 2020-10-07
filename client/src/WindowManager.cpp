/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** WindowManager
*/

#include "WindowManager.hpp"
#include <iostream>

#include <QtGui/QScreen>

Babel::Client::WindowManager::WindowManager(int argc, char **argv)
: QApplication(argc, argv)
, state(Babel::Client::WindowManager::State::Signup)
, widgets(int(State::LastEnum))
, windowNames(int(State::LastEnum))
, contactTimer()
, appWindow(nullptr)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    widgets[int(State::Login)] = std::make_unique<Gui::LoginWindow>(&appWindow);
    widgets[int(State::Login)]->hide();
    windowNames[int(State::Login)] = "Babel - Connexion";
    widgets[int(State::Signup)] = std::make_unique<Gui::SignupWindow>(&appWindow);
    widgets[int(State::Signup)]->hide();
    windowNames[int(State::Signup)] = "Babel - Inscription";
    widgets[int(State::Main)] = std::make_unique<Gui::MainWindow>(&appWindow);
    widgets[int(State::Main)]->hide();
    windowNames[int(State::Main)] = "Babel - Contacts";
    widgets[int(State::Call)] = std::make_unique<Gui::CallWindow>(&appWindow);
    widgets[int(State::Call)]->hide();
    windowNames[int(State::Call)] = "Babel - Appel";
    widgets[int(state)]->show();
    aboutPopUp.reset(nullptr);

    appWindow.setWindowTitle(windowNames[int(state)].c_str());
    appWindow.setStyleSheet("background-color: white;");
    appWindow.setFixedSize(640, 800);
    appWindow.move(screenGeometry.width() / 2 - appWindow.width() / 2, screenGeometry.height() / 2 - appWindow.height() / 2);
    appWindow.setWindowIcon(QIcon("./assets/logo.jpg"));
    appWindow.show();

    setState(State::Signup);
}

Babel::Client::WindowManager::~WindowManager()
{
    for (int i = int(State::Signup); i < int(State::LastEnum); i++) {
        widgets[i].reset();
    }
}

void Babel::Client::WindowManager::setState(const Babel::Client::WindowManager::State &state)
{
    if (state == this->state || state == State::LastEnum)
        return;
    for (int i = int(State::Signup); i < int(State::LastEnum); i++) {
        widgets[i]->hide();
    }
    this->state = state;
    widgets[int(state)]->show();
    appWindow.setWindowTitle(windowNames[int(state)].c_str());
}

const Babel::Client::WindowManager::State &Babel::Client::WindowManager::getState() const
{
    return (state);
}

Babel::Client::Gui::LoginWindow *Babel::Client::WindowManager::getLoginWindow() const
{
    if (Babel::Client::Gui::LoginWindow* c = dynamic_cast<Babel::Client::Gui::LoginWindow*>(widgets[int(State::Login)].get()))
    {
        return (c);
    }
    return (nullptr);
}

Babel::Client::Gui::SignupWindow *Babel::Client::WindowManager::getSignupWindow() const
{
    if (Babel::Client::Gui::SignupWindow* c = dynamic_cast<Babel::Client::Gui::SignupWindow*>(widgets[int(State::Signup)].get()))
    {
        return (c);
    }
    return (nullptr);
}

Babel::Client::Gui::MainWindow *Babel::Client::WindowManager::getMainWindow() const
{
    if (Babel::Client::Gui::MainWindow* c = dynamic_cast<Babel::Client::Gui::MainWindow*>(widgets[int(State::Main)].get()))
    {
        return (c);
    }
    return (nullptr);
}

Babel::Client::Gui::CallWindow *Babel::Client::WindowManager::getCallWindow() const
{
    if (Babel::Client::Gui::CallWindow* c = dynamic_cast<Babel::Client::Gui::CallWindow*>(widgets[int(State::Call)].get()))
    {
        return (c);
    }
    return (nullptr);
}

void Babel::Client::WindowManager::openAbout()
{
    aboutPopUp = std::make_unique<Gui::AboutWindow>();
}