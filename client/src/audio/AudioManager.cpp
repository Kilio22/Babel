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

Babel::Client::Audio::AudioManager::AudioManager()
    : inputDevice(std::make_unique<AudioInputDevice>(this))
    , outputDevice(std::make_unique<AudioOutputDevice>())
{
}

void Babel::Client::Audio::AudioManager::onSoundInputAvailable()
{
    emit this->inputAvailable(this->inputDevice->getSound());
}

void Babel::Client::Audio::AudioManager::startRecording() const
{
    this->inputDevice->startStream();
}

void Babel::Client::Audio::AudioManager::stopRecording() const
{
    this->inputDevice->stopStream();
}

void Babel::Client::Audio::AudioManager::startSpeaking() const
{
    this->outputDevice->startStream();
}

void Babel::Client::Audio::AudioManager::stopSpeaking() const
{
    this->outputDevice->stopStream();
}

void Babel::Client::Audio::AudioManager::queueAudio(const SoundBuffer &soundBuffer, const std::string &hostFrom) const
{
    this->outputDevice->setSound(soundBuffer, hostFrom);
}

#include "moc_AudioManager.cpp"
