/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioManager
*/

#include "AudioManager.hpp"
#include "AudioCompressor.hpp"
#include "AudioExtractor.hpp"
#include "AudioInputDevice.hpp"
#include "AudioOutputDevice.hpp"
#include "exceptions/AudioException.hpp"

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

void Babel::Client::Audio::AudioManager::queueAudio(const CompressedBuffer &compressedBuffer, const std::string &hostFrom)
{
    if (!this->audioExtractors.contains(hostFrom))
        this->audioExtractors.insert({ hostFrom, std::make_unique<AudioExtractor>() });
    this->outputDevice->setSound(this->audioExtractors[hostFrom]->extractAudio(compressedBuffer), hostFrom);
}

#include "moc_AudioManager.cpp"
