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
    : inCall(false)
{
    qRegisterMetaType<CompressedBuffer>("CompressedBuffer");
    QObject::connect(&this->audioManager, &AudioManager::inputAvailable, this, &CallManager::onInputAvailable);
    QObject::connect(&this->audioPacketSender, &AudioPacketSender::audioPacketRecieved, this, &CallManager::onOutputAvailable);
}

void Babel::Client::Audio::CallManager::beginCall(const std::vector<std::string> &hosts)
{
    this->inCall = true;
    this->audioPacketSender.connectTo(hosts);
    this->audioManager.startSpeaking();
    this->audioManager.startRecording();
}

void Babel::Client::Audio::CallManager::endCall()
{
    this->inCall = false;
    this->audioPacketSender.closeConnection();
    this->audioManager.stopSpeaking();
    this->audioManager.stopRecording();
}

void Babel::Client::Audio::CallManager::onInputAvailable(const CompressedBuffer &compressedBuffer)
{
    if (this->inCall)
        this->audioPacketSender.sendAudio(compressedBuffer);
}

void Babel::Client::Audio::CallManager::onOutputAvailable(const CompressedBuffer &compressedBuffer, const std::string &host)
{
    if (this->inCall)
        this->audioManager.queueAudio(compressedBuffer, host);
}

#include "moc_CallManager.cpp"
