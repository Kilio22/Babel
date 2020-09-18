/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioOutputDevice
*/

#include "AudioOutputDevice.hpp"
#include <iostream>

Babel::Audio::AudioOutputDevice::AudioOutputDevice() {}

void Babel::Audio::AudioOutputDevice::startStream()
{
    std::cout << "Streaming output" << std::endl;
}

void Babel::Audio::AudioOutputDevice::stopStream()
{
    std::cout << "Stopped streaming output" << std::endl;
}
