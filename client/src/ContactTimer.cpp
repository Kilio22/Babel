/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ContactTimer
*/

#include "ContactTimer.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"

#include <iostream>

Babel::Client::ContactTimer::ContactTimer(QWidget *parent)
: QWidget(parent)
, timer(this)
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(getContacts()));
    timer.start(5000);
    this->hide();
}

void Babel::Client::ContactTimer::getContacts()
{
    if (ServiceLocator::getInstance().get<WindowManager>().getState() == WindowManager::State::Main) {
        // TODO GOSSELIN
        // tu peux demander les contacts ici. Et quand tu les reçois tu peux les filer à MainWindow.



        std::cout << "Contact timer triggered" << std::endl;
    }
}

#include "moc_ContactTimer.cpp"