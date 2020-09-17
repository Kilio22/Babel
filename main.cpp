/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** main
*/

#include "./Counter.hpp"

int main(void)
{
    Counter a, b;
    QObject::connect(&a, &Counter::valueChanged, &b, &Counter::setValue);

    a.setValue(12); // a.value() == 12, b.value() == 12
    b.setValue(48); // a.value() == 12, b.value() == 48
}