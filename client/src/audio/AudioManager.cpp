/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioManager
*/

#include "AudioManager.hpp"
#include "AudioInputDevice.hpp"
#include "AudioOutputDevice.hpp"
#include "exceptions/AudioException.hpp"
#include "portaudio.h"
#include <iostream>

Babel::Audio::AudioManager::AudioManager()
    : inputDevice(std::make_unique<AudioInputDevice>())
    , outputDevice(std::make_unique<AudioOutputDevice>())
{
    auto err = Pa_Initialize();

    if (err != paNoError) {
        throw Exceptions::AudioException(Pa_GetErrorText(err));
    }
}

Babel::Audio::AudioManager::~AudioManager()
{
    Pa_Terminate();
}

void Babel::Audio::AudioManager::startRecording()
{
    this->inputDevice->startStream();
}

void Babel::Audio::AudioManager::stopRecording()
{
    this->inputDevice->stopStream();
}

void Babel::Audio::AudioManager::startListening()
{
    this->outputDevice->startStream();
}

void Babel::Audio::AudioManager::stopListening()
{
    this->outputDevice->stopStream();
}

#include "moc_AudioManager.cpp"
