/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioPacketSender
*/

#include "AudioPacketSender.hpp"
#include <iostream>

Babel::Audio::AudioPacketSender::AudioPacketSender() {}

Babel::Audio::AudioPacketSender::~AudioPacketSender() {}

void Babel::Audio::AudioPacketSender::sendAudio(const CompressedBuffer &compressedBuffer)
{
    this->recieveAudioTmp(compressedBuffer);
}

void Babel::Audio::AudioPacketSender::recieveAudioTmp(const CompressedBuffer &compressedBuffer)
{
    emit this->audioPacketRecieved(compressedBuffer);
}

#include "moc_AudioPacketSender.cpp"
