/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CallWindow
*/

#include "CallWindow.hpp"

#include <QtGui/QScreen>
#include <QtGui/QGuiApplication>
#include <QtGui/QPixmap>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayoutItem>
#include <iostream>

#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include "CommandManager.hpp"

Babel::Client::Gui::CallWindow::CallWindow(QWidget *parent)
: QMainWindow(parent)
, area(this)
, widget()
, avatar(this)
, myName(this)
, vLayout()
, callBtn("Raccrocher", this)
, errorStr(this)
, username("Default Username")
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    std::string path = "./assets/avatars/" + std::to_string(username[0] % 26 + 1) + ".png";
    QPixmap pixmap(path.c_str());
    QRegion *region;

    this->setWindowTitle("Babybel - Call");
    this->setStyleSheet("background-color: white;");
    this->setFixedSize(640, 800);
    this->move(screenGeometry.width() / 2 - this->width() / 2, screenGeometry.height() / 2 - this->height() / 2);
    this->setWindowIcon(QIcon("./assets/logo.jpg"));

    avatar.setPixmap(pixmap);
    avatar.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    avatar.setFixedSize(200, 200);
    region = new QRegion(0, 0, avatar.width(), avatar.height(), QRegion::Ellipse);
    avatar.setScaledContents(true);
    avatar.setMask(*region);
    avatar.move(20, 20);

    area.setFixedSize(600, 500);
    area.setStyleSheet("background-color: #d4d3d2;");
    area.move(20, 280);
    area.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    area.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    area.setWidgetResizable(true);
    widget.setLayout(&vLayout);

    myName.setFixedSize(380, 100);
    myName.move(240, 20);
    myName.setAlignment(Qt::AlignCenter);
    myName.setText(username.c_str());
    myName.setStyleSheet(       "color: black;"
                                "font-size: 32px;");

    callBtn.setFixedSize(380, 100);
    callBtn.setStyleSheet(  "background-color: #3b3b3b;"
                            "color: white;"
                            "border-radius: 25;"
                            "selection-background-color: #636363;"
                            "font-size: 20px;");
    callBtn.move(240, 120);

    errorStr.setFixedSize(640, 64);
    errorStr.move(this->width() / 2 - errorStr.width() / 2, 216);
    errorStr.setAlignment(Qt::AlignCenter);
    errorStr.setStyleSheet(     "color: red;"
                                "font-size: 12px;");
    errorStr.setText("");

    myName.show();
    area.show();
    avatar.show();
    errorStr.show();

    QObject::connect(&this->callBtn, SIGNAL (pressed()), this, SLOT (EndCallClicked()));
}

void Babel::Client::Gui::CallWindow::EndCallClicked()
{
    ServiceLocator::getInstance().get<CommandManager>().stopCall();
    reset();
}

void Babel::Client::Gui::CallWindow::EndCallWorked()
{
    ServiceLocator::getInstance().get<WindowManager>().setState(WindowManager::State::Main);
}

void Babel::Client::Gui::CallWindow::setCallList(const std::vector<std::string> &nameList)
{
    callList.clear();
    for (int i = 0; i < nameList.size(); i++) {
        QHBoxLayout *layout = new QHBoxLayout();
        std::unique_ptr<PersonMainWidget> tmp = std::make_unique<PersonMainWidget>(&widget, nameList[i], false, ((i + 1) * 20) + i * 80);
        tmp->show();
        layout->addWidget(tmp.get());
        vLayout.addLayout(layout);
        callList.push_back(std::move(tmp));
    }
    area.setWidget(&widget);
}

void Babel::Client::Gui::CallWindow::reset()
{
    //callList.clear();
    errorStr.setText("");
}

void Babel::Client::Gui::CallWindow::setUsername(const std::string &name)
{
    std::string path = "./assets/avatars/" + std::to_string(name[0] % 26 + 1) + ".png";
    QPixmap pixmap(path.c_str());
    QRegion *region;

    username = name;
    avatar.setPixmap(pixmap);
    avatar.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    avatar.setFixedSize(200, 200);
    region = new QRegion(0, 0, avatar.width(), avatar.height(), QRegion::Ellipse);
    avatar.setScaledContents(true);
    avatar.setMask(*region);
    avatar.move(20, 20);
    myName.setText(username.c_str());
}

void Babel::Client::Gui::CallWindow::setError(const std::string &error)
{
    reset();
    errorStr.setText(error.c_str());
}

#include "moc_CallWindow.cpp"