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
#include <iomanip>
#include <iostream>

Babel::Client::Audio::AudioManager::AudioManager()
    : inputDevice(std::make_unique<AudioInputDevice>(this))
    , outputDevice(std::make_unique<AudioOutputDevice>())
    , audioCompressor(std::make_unique<AudioCompressor>())
{
}

void Babel::Client::Audio::AudioManager::onSoundInputAvailable()
{
    emit this->inputAvailable(this->audioCompressor->compressAudio(this->inputDevice->getSound()));
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

void Babel::Client::Audio::AudioManager::stopSpeaking()
{
    this->outputDevice->stopStream();
    this->audioExtractors.clear();
}

// #include <iomanip>

void Babel::Client::Audio::AudioManager::queueAudio(const CompressedBuffer &compressedBuffer, const std::string &hostFrom)
{
    std::cout << "Extracting " << compressedBuffer.size << ":";
    for (auto &sample : compressedBuffer.samples)
        std::cout << " " << (int)sample;
    std::cout << std::endl;

    if (!this->audioExtractors.contains(hostFrom))
        this->audioExtractors.insert({ hostFrom, std::make_unique<AudioCompressor>() });
    const auto &soundBuffer = this->audioExtractors[hostFrom]->extractAudio(compressedBuffer);

    std::cout << "Extracted " << soundBuffer.samples.size() << ":";
    for (auto &sample : soundBuffer.samples)
        std::cout << " " << std::setprecision(3) << sample;
    std::cout << std::endl;

    this->outputDevice->setSound(soundBuffer, hostFrom);
}

#include "moc_AudioManager.cpp"
