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
#include <iomanip>

Babel::Audio::AudioManager::AudioManager()
    : inputDevice(nullptr)
    , outputDevice(nullptr)
{
    auto err = Pa_Initialize();

    if (err != paNoError) {
        throw Client::Exceptions::AudioException(Pa_GetErrorText(err));
    }
    this->inputDevice = std::make_unique<AudioInputDevice>(this);
    this->outputDevice = std::make_unique<AudioOutputDevice>();
}

Babel::Audio::AudioManager::~AudioManager()
{
    Pa_Terminate();
}

void Babel::Audio::AudioManager::onSoundInputAvailable()
{
    emit this->inputAvailable(this->inputDevice->getSound());
}

void Babel::Audio::AudioManager::queueAudio(const SoundBuffer &soundBuffer)
{
    this->outputDevice->setSound(soundBuffer);
}

void Babel::Audio::AudioManager::startRecording()
{
    this->inputDevice->startStream();
}

void Babel::Audio::AudioManager::stopRecording()
{
    this->inputDevice->stopStream();
}

void Babel::Audio::AudioManager::startSpeaking()
{
    this->outputDevice->startStream();
}

void Babel::Audio::AudioManager::stopSpeaking()
{
    this->outputDevice->stopStream();
}

#include "moc_AudioManager.cpp"
