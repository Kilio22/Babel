/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** PersonMainWidget
*/

#ifndef PERSONMAINWIDGET_HPP_
#define PERSONMAINWIDGET_HPP_

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>

namespace Babel::Client::Gui {

    class PersonMainWidget : public QWidget {
        Q_OBJECT
        public:
            PersonMainWidget(QWidget *parent = nullptr, std::string nameStr = std::string("Name"), bool canCheck = true, int ypos = 20, bool connected = true);
            ~PersonMainWidget() = default;

            bool checkSelected() const;
            void setCheck(bool newValue);
            const std::string &getName() const;

        private:
            QLabel bgLabel;
            QLabel avatar;
            QLabel username;
            QCheckBox checkbox;
            std::string nameStr;
    };
};

#endif /* !PERSONMAINWIDGET_HPP_ */
