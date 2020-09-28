/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** MainWindow
*/

#include "MainWindow.hpp"

#include <QtGui/QScreen>
#include <QtGui/QGuiApplication>
#include <QtGui/QPixmap>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayoutItem>
#include <iostream>

#include "ServiceLocator.hpp"
#include "CommandManager.hpp"
#include "WindowManager.hpp"

Babel::Client::Gui::MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, area(this)
, widget()
, avatar(this)
, myName(this)
, contactLine(this)
, vLayout()
, contactBtn("Ajouter" ,this)
, callBtn("Appeler", this)
, errorStr(this)
, username("Default Username")
, disconnectBtn("Déconnexion", this)
, aboutBtn("À propos", this)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    std::string path = "./assets/avatars/" + std::to_string(username[0] % 26 + 1) + ".png";
    QPixmap pixmap(path.c_str());
    QRegion *region;

    this->setWindowTitle("Babybel - Contacts");
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

    area.setFixedSize(600, 350);
    area.setStyleSheet("background-color: #d4d3d2;");
    area.move(20, 280);
    area.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    area.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    area.setWidgetResizable(true);
    widget.setLayout(&vLayout);

    contactLine.setFixedSize(380, 80);
    contactLine.move(20, 650);
    contactLine.setStyleSheet(  "border-radius: 24;"
                                "font-size: 20px;"
                                "padding: 12px;"
                                "border: 2px solid black;");
    contactLine.setPlaceholderText("Ajouter un contact");

    contactBtn.setFixedSize(200, 80);
    contactBtn.setStyleSheet(   "background-color: #3b3b3b;"
                                "color: white;"
                                "border-radius: 25;"
                                "selection-background-color: #636363;"
                                "font-size: 20px;");
    contactBtn.move(420, 650);

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

    disconnectBtn.setFixedSize(290, 20);
    disconnectBtn.setStyleSheet( "background-color: white;"
                            "color: gray;"
                            "border-radius: 25;"
                            "selection-background-color: white;"
                            "font-size: 16px;");
    disconnectBtn.move(20, 760);

    aboutBtn.setFixedSize(290, 20);
    aboutBtn.setStyleSheet( "background-color: white;"
                            "color: gray;"
                            "border-radius: 25;"
                            "selection-background-color: white;"
                            "font-size: 16px;");
    aboutBtn.move(310, 760);

    myName.show();
    area.show();
    avatar.show();
    contactLine.show();
    contactBtn.show();
    errorStr.show();
    disconnectBtn.show();
    aboutBtn.show();

    QObject::connect(&this->contactBtn, SIGNAL (pressed()), this, SLOT (addContact()));
    QObject::connect(&this->callBtn, SIGNAL (pressed()), this, SLOT (callClicked()));
    QObject::connect(&this->disconnectBtn, SIGNAL(pressed()), this, SLOT(disconnect()));
    QObject::connect(&this->aboutBtn, SIGNAL(pressed()), this, SLOT(openAbout()));
}

void Babel::Client::Gui::MainWindow::addContact()
{
    ServiceLocator::getInstance().get<CommandManager>().addContact(contactLine.text().toStdString());
    reset();
}

void Babel::Client::Gui::MainWindow::callClicked()
{
    // TODO ICI NATHAN
    //getUsersCalled pour recup les utilisateurs cochés.
    reset();
    // Si le call se lance, faites ça :
    ServiceLocator::getInstance().get<WindowManager>().setState(WindowManager::State::Call);
    ServiceLocator::getInstance().get<WindowManager>().getCallWindow()->setUsername(username);
    ServiceLocator::getInstance().get<WindowManager>().getCallWindow()->setCallList({"un utilisateur", "un autre utilisateur"}); // Faut filer un vecteur des gens qui sont dans le call. Si qqn quitte tu peux redonner le vector pour update la liste de la gui aussi.
}

void Babel::Client::Gui::MainWindow::setContacts(const std::vector<std::string> &nameList)
{
    contacts.clear();
    for (int i = 0; i < nameList.size(); i++) {
        QHBoxLayout *layout = new QHBoxLayout();
        std::unique_ptr<PersonMainWidget> tmp = std::make_unique<PersonMainWidget>(&widget, nameList[i], true, ((i + 1) * 20) + i * 80);
        tmp->show();
        layout->addWidget(tmp.get());
        vLayout.addLayout(layout);
        contacts.push_back(std::move(tmp));
    }
    area.setWidget(&widget);
}

void Babel::Client::Gui::MainWindow::reset()
{
    //contacts.clear();
    contactLine.clear();
    errorStr.setText("");
}

void Babel::Client::Gui::MainWindow::setUsername(const std::string &name)
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

void Babel::Client::Gui::MainWindow::setError(const std::string &error)
{
    reset();
    errorStr.setText(error.c_str());
}

const std::vector<std::string> Babel::Client::Gui::MainWindow::getUsersCalled() const
{
    std::vector<std::string> retVal;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i]->checkSelected())
            retVal.push_back(contacts[i]->getName());
    }
    return retVal;
}

void Babel::Client::Gui::MainWindow::openAbout() const
{
    std::cout << "OPEN ABOUT HERE" << std::endl;
}

void Babel::Client::Gui::MainWindow::disconnect() const
{
    // TODO GOSSELIN
    // Tu peux déconnecter le mec ici.
    ServiceLocator::getInstance().get<WindowManager>().setState(WindowManager::State::Login);
}

#include "moc_MainWindow.cpp"