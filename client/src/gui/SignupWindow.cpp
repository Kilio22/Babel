/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** SignupWindow
*/

#include "SignupWindow.hpp"
#include "CommandManager.hpp"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"
#include "exceptions.h"
#include <QtGui/QGuiApplication>
#include <QtGui/QPixmap>
#include <iostream>

Babel::Client::Gui::SignupWindow::SignupWindow(QWidget *parent)
: QWidget(parent)
, mainWidget(this)
, submitBtn("S'inscrire", &mainWidget)
, logo(&mainWidget)
, username(&mainWidget)
, password(&mainWidget)
, loginBtn("Se connecter", &mainWidget)
, bottomText(&mainWidget)
, topText(&mainWidget)
, loaderGif(this)
, movie("./assets/loader.gif")
, lastUsername("Default Username")
{
    QPixmap pm("./assets/Babybel.png");

    this->setStyleSheet("background-color: white;");
    this->setFixedSize(640, 800);

    mainWidget.setStyleSheet("background-color: white;");
    mainWidget.setFixedSize(640, 800);

    logo.setPixmap(pm);
    logo.setScaledContents(true);
    logo.resize(484, 200);
    logo.move(this->width() / 2 - logo.width() / 2, 50);

    loaderGif.setFixedSize(50, 50);
    loaderGif.move(this->width() / 2 - loaderGif.width()  / 2, this->height() / 2 - loaderGif.height()  / 2);
    loaderGif.setMovie(&movie);

    movie.setScaledSize(QSize(50, 50));
    movie.start();

    submitBtn.setFixedSize(350, 64);
    submitBtn.setStyleSheet("background-color: #3b3b3b;"
                            "color: white;"
                            "border-radius: 25;"
                            "selection-background-color: #636363;"
                            "font-size: 20px;");
    submitBtn.move(this->width() / 2 - submitBtn.width() / 2, 550);

    loginBtn.setFixedSize(350, 64);
    loginBtn.setStyleSheet( "background-color: white;"
                            "color: gray;"
                            "border-radius: 25;"
                            "selection-background-color: white;"
                            "font-size: 20px;");
    loginBtn.move(this->width() / 2 - loginBtn.width() / 2, 650);

    username.setFixedSize(350, 64);
    username.move(this->width() / 2 - username.width() / 2, 350);
    username.setStyleSheet( "border-radius: 24;"
                            "font-size: 20px;"
                            "padding: 12px;"
                            "border: 2px solid black;");
    username.setPlaceholderText("Pseudo");

    password.setFixedSize(350, 64);
    password.move(this->width() / 2 - password.width() / 2, 450);
    password.setStyleSheet( "border-radius: 24;"
                            "font-size: 20px;"
                            "padding: 12px;"
                            "border: 2px solid black;");
    password.setPlaceholderText("Mot de passe");
    password.setEchoMode(QLineEdit::Password);

    loaderGif.hide();
    mainWidget.show();
    submitBtn.show();
    logo.show();
    username.show();
    password.show();
    bottomText.show();
    topText.show();

    bottomText.setFixedSize(640, 64);
    bottomText.move(this->width() / 2 - bottomText.width() / 2, 725);
    bottomText.setAlignment(Qt::AlignCenter);
    bottomText.setText("Mot de passe oublié ? Bah c'est dommage mdr");
    bottomText.setStyleSheet(   "color: gray;"
                                "font-size: 18px;");

    topText.setFixedSize(640, 64);
    topText.move(this->width() / 2 - topText.width() / 2, 280);
    topText.setAlignment(Qt::AlignCenter);
    topText.setStyleSheet(  "color: red;"
                            "font-size: 12px;");
    topText.setText("");

    QObject::connect(&this->submitBtn, SIGNAL(pressed()), this, SLOT(submitSignup()));
    QObject::connect(&this->loginBtn, SIGNAL(pressed()), this, SLOT(switchToLogin()));
}

void Babel::Client::Gui::SignupWindow::evaluateForms()
{
    if (username.text().toStdString().size() == 0)
        throw Babel::Client::Exceptions::MissingUsernameException(ERROR_STR, "Missing Username");
    if (password.text().toStdString().size() == 0)
        throw Babel::Client::Exceptions::MissingPasswordException(ERROR_STR, "Missing Password");
    for (auto c : username.text().toStdString()) {
        if (!isalnum(c))
            throw Babel::Client::Exceptions::InvalidUsernameException(ERROR_STR, "Invalid Username Format.");
    }
    for (auto c : password.text().toStdString()) {
        if (!isalnum(c))
            throw Babel::Client::Exceptions::InvalidPasswordException(ERROR_STR, "Invalid Password Format.");
    }
    if (username.text().toStdString().size() < 3 || username.text().toStdString().size() > 32)
        throw Babel::Client::Exceptions::InvalidUsernameException(ERROR_STR, "Invalid Username Format.");
    if (password.text().toStdString().size() < 3 || password.text().toStdString().size() > 42)
        throw Babel::Client::Exceptions::InvalidPasswordException(ERROR_STR, "Invalid Password Format.");
}

void Babel::Client::Gui::SignupWindow::submitSignup()
{
    try {
        evaluateForms();
        lastUsername = username.text().toStdString();
        ServiceLocator::getInstance().get<CommandManager>().signup(username.text().toStdString(), password.text().toStdString());
    } catch (const Babel::Client::Exceptions::InvalidUsernameException &e) {
        (void)e;
        topText.setText("Un pseudo doit contenir entre 3 et 32 caractères alphanumériques.");
        return;
    } catch (const Babel::Client::Exceptions::InvalidPasswordException &e) {
        (void)e;
        topText.setText("Un mot de passe doit contenir entre 3 et 42 caractères alphanumériques.");
        return;
    } catch (const Babel::Client::Exceptions::MissingUsernameException &e) {
        (void)e;
        topText.setText("Veuillez entrer votre pseudo & votre mot de passe pour vous inscrire.");
        return;
    } catch (const Babel::Client::Exceptions::MissingPasswordException &e) {
        (void)e;
        topText.setText("Veuillez entrer votre pseudo & votre mot de passe pour vous inscrire.");
        return;
    }
    reset();
    mainWidget.hide();
    loaderGif.show();
    //activer le truc qui tourne ici
}

void Babel::Client::Gui::SignupWindow::switchToLogin()
{
    reset();
    Babel::Client::ServiceLocator::getInstance().get<Babel::Client::WindowManager>().setState(Babel::Client::WindowManager::State::Login);
}

void Babel::Client::Gui::SignupWindow::reset()
{
    username.clear();
    password.clear();
    topText.setText("");
}

void Babel::Client::Gui::SignupWindow::setError(const std::string & errorStr)
{
    reset();
    mainWidget.show();
    loaderGif.hide();
    topText.setText(errorStr.c_str());
}

void Babel::Client::Gui::SignupWindow::signupWorked()
{
    this->username.clear();
    password.clear();
    topText.setText("");
    mainWidget.show();
    loaderGif.hide();
    ServiceLocator::getInstance().get<WindowManager>().setState(WindowManager::State::Login);
    ServiceLocator::getInstance().get<WindowManager>().getMainWindow()->setUsername(lastUsername);
}

#include "moc_SignupWindow.cpp"