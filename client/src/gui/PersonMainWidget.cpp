/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** PersonMainWidget
*/

#include "PersonMainWidget.hpp"
#include <QtGui/QPixmap>

Babel::Client::Gui::PersonMainWidget::PersonMainWidget(QWidget *parent, std::string nameStr, bool canCheck, int ypos)
: QWidget(parent)
, bgLabel(this)
, avatar(this)
, username(this)
, checkbox(this)
, nameStr(nameStr)
{
    std::string path = "./assets/avatars/" + std::to_string(nameStr[0] % 26 + 1) + ".png";
    QPixmap pixmap(path.c_str());
    QRegion *region;

    avatar.setPixmap(pixmap);
    avatar.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    avatar.setFixedSize(60, 60);
    region = new QRegion(0, 0, avatar.width(), avatar.height(), QRegion::Ellipse);
    avatar.setScaledContents(true);
    avatar.setMask(*region);
    avatar.show();
    avatar.move(10, 10);

    this->setFixedSize(540, 80);
    this->setStyleSheet("background-color: white;"
                        "border-radius: 25;");
    this->move(20, ypos);

    bgLabel.setFixedSize(540, 80);
    bgLabel.setStyleSheet("background-color: white;"
                        "border-radius: 25;");

    username.setFixedSize(260, 64);
    username.move(100, 10);
    //username.setAlignment(Qt::AlignLeft);
    username.setText(nameStr.c_str());
    username.setStyleSheet(   "color: black;"
                                "font-size: 18px;");

    checkbox.setFixedSize(60, 60);
    checkbox.move(470, 10);

    bgLabel.show();
    avatar.show();
    username.show();
    if (canCheck)
        checkbox.show();
    else
        checkbox.hide();
}

bool Babel::Client::Gui::PersonMainWidget::checkSelected() const
{
    if (checkbox.checkState() == Qt::CheckState::Unchecked)
        return false;
    return true;
}

const std::string &Babel::Client::Gui::PersonMainWidget::getName() const
{
    return nameStr;
}

#include "moc_PersonMainWidget.cpp"
