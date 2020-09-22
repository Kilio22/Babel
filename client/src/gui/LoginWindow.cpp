/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** LoginWindow
*/

#include "LoginWindow.hpp"

#include <QtGui/QScreen>
#include <QtGui/QGuiApplication>
#include <QtGui/QPixmap>

#include "exceptions.h"
#include "ServiceLocator.hpp"
#include "WindowManager.hpp"

Babel::Client::Gui::LoginWindow::LoginWindow(QWidget *parent) 
: QMainWindow(parent)
, loginBtn("Se connecter", this)
, logo(this)
, username(this)
, password(this)
, signupBtn("Créer un compte", this)
, bottomText(this)
, topText(this)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    QPixmap pm("./assets/Babybel.png");

    this->setWindowTitle("Babybel - Connexion");
    this->setStyleSheet("background-color: white;");
    this->setFixedSize(640, 800);
    this->move(screenGeometry.width() / 2 - this->width() / 2, screenGeometry.height() / 2 - this->height() / 2);

    logo.setPixmap(pm);
    logo.setScaledContents(true);
    logo.resize(484, 200);
    logo.move(this->width() / 2 - logo.width() / 2, 50);

    loginBtn.setFixedSize(350, 64);
    loginBtn.setStyleSheet( "background-color: #3b3b3b;"
                            "color: white;"
                            "border-radius: 25;"
                            "selection-background-color: #636363;"
                            "font-size: 20px;");
    loginBtn.move(this->width() / 2 - loginBtn.width()  / 2, 550);

    signupBtn.setFixedSize(350, 64);
    signupBtn.setStyleSheet( "background-color: white;"
                            "color: gray;"
                            "border-radius: 25;"
                            "selection-background-color: white;"
                            "font-size: 20px;");
    signupBtn.move(this->width() / 2 - signupBtn.width()  / 2, 650);

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

    loginBtn.show();
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
    topText.setStyleSheet(      "color: red;"
                                "font-size: 12px;");
    topText.setText("");

    QObject::connect(&this->loginBtn, SIGNAL (pressed()), this, SLOT (submitLogin()));
    QObject::connect(&this->signupBtn, SIGNAL (pressed()), this, SLOT (switchToSignup()));
}

void Babel::Client::Gui::LoginWindow::evaluateForms() {
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
    if (password.text().toStdString().size() < 3 || password.text().toStdString().size() > 32)
        throw Babel::Client::Exceptions::InvalidPasswordException(ERROR_STR, "Invalid Password Format.");
}

void Babel::Client::Gui::LoginWindow::submitLogin() {
    try {
        evaluateForms();
        // TODO
        // POUR ANTOINE (ou moi plus tard jsp).
        // On se connecte ici. Si ça marche pas, throw InvalidCredentialsException ou LoginFailedException.
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
        topText.setText("Veuillez entrer votre pseudo & votre mot de passe pour vous connecter.");
        return;
    } catch (const Babel::Client::Exceptions::MissingPasswordException &e) {
        (void)e;
        topText.setText("Veuillez entrer votre pseudo & votre mot de passe pour vous connecter.");
        return;
    } catch (const Babel::Client::Exceptions::InvalidCredentialsException &e) {
        // TODO
        // POUR ANTOINE (ou moi plus tard jsp).
        // Tu throw ça quand le username / mdp est pas bon. Genre le mdp est pas bon, l'username existe pas etc...
        (void)e;
        topText.setText("Pseudo ou mot de passe invalide.");
        return;
    } catch (const Babel::Client::Exceptions::LoginFailedException &e) {
        // TODO
        // POUR ANTOINE (ou moi plus tard jsp).
        // Tu throw ça quand la connection au serv marche pas.
        (void)e;
        topText.setText("La connexion au serveur à échoué.");
        return;
    }
    reset();
    // Stocker qu'on est connecté qqpart ou chai pas.
    // Changer de fenetre. (la fenetre d'après existe pas encore ça vient)
}

void Babel::Client::Gui::LoginWindow::switchToSignup() {
    reset();
    Babel::Client::ServiceLocator::getInstance().get<Babel::Client::WindowManager>().setState(Babel::Client::WindowManager::State::Signup);
}

void Babel::Client::Gui::LoginWindow::reset() {
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    username.text().clear();
    password.text().clear();
    topText.setText("");
    this->setFixedSize(640, 800);
    this->move(screenGeometry.width() / 2 - this->width() / 2, screenGeometry.height() / 2 - this->height() / 2);
}

#include "moc_LoginWindow.cpp"