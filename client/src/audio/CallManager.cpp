/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CallManager
*/

#include "CallManager.hpp"
#include <QtCore/QDebug>
#include <iostream>

Babel::Client::Audio::CallManager::CallManager()
    : audioCompressor(std::make_unique<AudioCompressor>())
{
    qRegisterMetaType<SoundBuffer>("SoundBuffer");
    QObject::connect(&this->audioManager, &AudioManager::inputAvailable, this, &CallManager::onInputAvailable);
    QObject::connect(&this->audioPacketSender, &AudioPacketSender::audioPacketRecieved, this, &CallManager::onOutputAvailable);
}

void Babel::Client::Audio::CallManager::beginCall(const std::vector<std::string> &hosts)
{
    this->audioPacketSender.connectTo(hosts);
    this->audioManager.startSpeaking();
    this->audioManager.startRecording();
}

void Babel::Client::Audio::CallManager::endCall()
{
    this->audioPacketSender.closeConnection();
    this->audioManager.stopSpeaking();
    this->audioManager.stopRecording();
}

void Babel::Client::Audio::CallManager::onInputAvailable(const SoundBuffer &soundBuffer)
{
    this->audioPacketSender.sendAudio(this->audioCompressor->compressAudio(soundBuffer));
}

#include <iomanip>

void Babel::Client::Audio::CallManager::onOutputAvailable(const CompressedBuffer &compressedBuffer, const std::string &host)
{
    std::cout << "Extracting " << compressedBuffer.size << ":";
    for (auto &sample : compressedBuffer.samples)
        std::cout << " " << (int)sample;
    std::cout << std::endl;
    const auto &audio = this->audioCompressor->extractAudio(compressedBuffer);

    std::cout << "Extracted " << audio.samples.size() << ":";
    for (auto &sample : audio.samples)
        std::cout << " " << std::setprecision(3) << sample;
    std::cout << std::endl;
    // std::cout << "onOutputAvailable: " << audio.samples[0] << " (" << host << ")" << std::endl;
    this->audioManager.queueAudio(audio, host);
}

#include "moc_CallManager.cpp"
