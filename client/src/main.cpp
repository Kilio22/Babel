/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** main
*/

#include <QApplication>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QFont>
#include <QFontDialog>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QTextStream>
#include <QWidget>
#include <opus.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

int main(void)
{
    std::map<int, int> mymap = {{1, 1}, {2, 2}};

    std::cout << "hello, world!" << std::endl;
    return mymap.contains(1);
}
