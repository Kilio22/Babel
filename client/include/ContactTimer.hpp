/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ContactTimer
*/

#ifndef CONTACTTIMER_HPP_
#define CONTACTTIMER_HPP_

#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtGui/QMovie>
#include <QtCore/QTimer>

namespace Babel::Client {

    class ContactTimer : public QWidget
    {
        Q_OBJECT
        private:
            QTimer timer;

        public:
            ContactTimer(QWidget *parent = nullptr);
            ~ContactTimer() = default;

        private slots:
            void getContacts();
    };
};

#endif /* !CONTACTTIMER_HPP_ */
