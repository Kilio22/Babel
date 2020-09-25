/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioPacketSender
*/

#include "AudioPacketSender.hpp"
#include "QtUdpClient.hpp"
#include <iostream>

Babel::Audio::AudioPacketSender::AudioPacketSender()
    : udpClient(std::make_unique<Client::Network::QtUdpClient>())
{
    auto newClient = new Client::Network::QtUdpClient();

    QObject::connect(newClient, &Client::Network::QtUdpClient::dataAvailable, this, &AudioPacketSender::onDataAvailable);
    this->udpClient.reset(newClient);
}

void Babel::Audio::AudioPacketSender::connectTo(const std::vector<std::string> &hosts)
{
    this->hosts = hosts;
    this->udpClient->connect(DefaultAudioPort);
}

void Babel::Audio::AudioPacketSender::sendAudio(const CompressedBuffer &compressedBuffer)
{
    SoundPacket soundPacket = {};
    char *ptr;

    soundPacket.size = compressedBuffer.size;
    std::memcpy(soundPacket.data, compressedBuffer.samples.data(), compressedBuffer.size);
    ptr = reinterpret_cast<char *>(&soundPacket);
    for (auto &host : this->hosts)
        this->udpClient->send(ptr, sizeof(SoundPacket), host, DefaultAudioPort);
}

void Babel::Audio::AudioPacketSender::onDataAvailable()
{
    CompressedBuffer compressedBuffer;
    std::vector<char> data = this->udpClient->getData();
    SoundPacket *packetPtr = reinterpret_cast<SoundPacket *>(data.data());

    compressedBuffer.size = packetPtr->size;
    compressedBuffer.samples.assign(packetPtr->data, packetPtr->data + packetPtr->size);
    emit this->audioPacketRecieved(compressedBuffer);
}

#include "moc_AudioPacketSender.cpp"
