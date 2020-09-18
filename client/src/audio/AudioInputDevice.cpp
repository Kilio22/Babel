/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioInputDevice
*/

#include "AudioInputDevice.hpp"
#include <iostream>

Babel::Audio::AudioInputDevice::AudioInputDevice() {}

void Babel::Audio::AudioInputDevice::startStream()
{
    std::cout << "Steaming input" << std::endl;
}

void Babel::Audio::AudioInputDevice::stopStream()
{
    std::cout << "Stopped streaming input" << std::endl;
}
