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
#include <iostream>
#include <iomanip>

Babel::Audio::AudioManager::AudioManager()
    : inputDevice(std::make_unique<AudioInputDevice>(this))
    , outputDevice(std::make_unique<AudioOutputDevice>())
{
}

void Babel::Audio::AudioManager::onSoundInputAvailable()
{
    emit this->inputAvailable(this->inputDevice->getSound());
}

void Babel::Audio::AudioManager::startRecording() const
{
    this->inputDevice->startStream();
}

void Babel::Audio::AudioManager::stopRecording() const
{
    this->inputDevice->stopStream();
}

void Babel::Audio::AudioManager::startSpeaking() const
{
    this->outputDevice->startStream();
}

void Babel::Audio::AudioManager::stopSpeaking() const
{
    this->outputDevice->stopStream();
}

void Babel::Audio::AudioManager::queueAudio(const SoundBuffer &soundBuffer, const std::string &hostFrom) const
{
    this->outputDevice->setSound(soundBuffer, hostFrom);
}

#include "moc_AudioManager.cpp"
