/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ContactTimer
*/

#include "ContactTimer.hpp"
#include "ServiceLocator.hpp"
#include "CommandManager.hpp"
#include "WindowManager.hpp"

#include <iostream>

Babel::Client::ContactTimer::ContactTimer(QWidget *parent)
: QWidget(parent)
, timer(this)
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(getContacts()));
    timer.start(1000);
    this->hide();
}

void Babel::Client::ContactTimer::getContacts()
{
    if (ServiceLocator::getInstance().get<WindowManager>().getState() == WindowManager::State::Main) {
        ServiceLocator::getInstance().get<CommandManager>().getContacts();
//        std::cout << "Contact timer triggered" << std::endl;
    }
}

#include "moc_ContactTimer.cpp"