/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CallManager
*/

#include "CallManager.hpp"
#include <QtCore/QDebug>
#include <iostream>

Babel::Audio::CallManager::CallManager()
    : audioCompressor(std::make_unique<AudioCompressor>())
{
    qRegisterMetaType<SoundBuffer>("SoundBuffer");
    QObject::connect(&this->audioManager, &AudioManager::inputAvailable, this, &CallManager::onInputAvailable);
    QObject::connect(&this->audioPacketSender, &AudioPacketSender::audioPacketRecieved, this, &CallManager::onOutputAvailable);
}

Babel::Audio::CallManager::~CallManager() {}

void Babel::Audio::CallManager::beginCall()
{
    this->audioManager.startRecording();
    this->audioManager.startSpeaking();
}

void Babel::Audio::CallManager::endCall()
{
    this->audioManager.stopRecording();
    this->audioManager.stopSpeaking();
}

void Babel::Audio::CallManager::onInputAvailable(const SoundBuffer &soundBuffer)
{
    this->audioPacketSender.sendAudio(this->audioCompressor->compressAudio(soundBuffer));
}

void Babel::Audio::CallManager::onOutputAvailable(const CompressedBuffer &compressedBuffer)
{
    this->audioManager.queueAudio(this->audioCompressor->extractAudio(compressedBuffer));
}

#include "moc_CallManager.cpp"
