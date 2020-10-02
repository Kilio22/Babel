/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioPacketSender
*/

#include "AudioPacketSender.hpp"
#include "QtUdpClient.hpp"
#include <iostream>

using namespace Babel::Client::Network;

Babel::Client::Audio::AudioPacketSender::AudioPacketSender()
    : udpClient(nullptr)
{
}

void Babel::Client::Audio::AudioPacketSender::connectTo(const std::vector<std::string> &hosts)
{
    auto newClient = new QtUdpClient();

    QObject::connect(newClient, &QtUdpClient::dataAvailable, this, &AudioPacketSender::onDataAvailable);
    this->hosts = hosts;
    this->udpClient.reset(newClient);
    this->udpClient->connect(DefaultAudioPort);
}

void Babel::Client::Audio::AudioPacketSender::closeConnection()
{
    this->udpClient->closeConnection();
    this->udpClient.reset();
}

void Babel::Client::Audio::AudioPacketSender::sendAudio(const CompressedBuffer &compressedBuffer)
{
    IUdpClient::DataPacket dataPacket;
    SoundPacket soundPacket = {};
    char *ptr;

    soundPacket.timestamp = std::time(nullptr);
    soundPacket.size = compressedBuffer.size;
    std::memcpy(soundPacket.data, compressedBuffer.samples.data(), compressedBuffer.size);
    ptr = reinterpret_cast<char *>(&soundPacket);

    dataPacket.port = DefaultAudioPort;
    dataPacket.data.assign(ptr, ptr + sizeof(SoundPacket));
    for (auto &host : this->hosts) {
        dataPacket.host = host;
//        std::cout << "Sending packet of size " << dataPacket.data.size() << " (" << soundPacket.size << ") to " << dataPacket.host << std::endl;
        this->udpClient->send(dataPacket);
    }
}

void Babel::Client::Audio::AudioPacketSender::onDataAvailable()
{
    CompressedBuffer compressedBuffer;
    IUdpClient::DataPacket dataPacket = this->udpClient->getData();
    SoundPacket *soundPacketPtr = reinterpret_cast<SoundPacket *>(dataPacket.data.data());

//    std::cout << "Recieved packet of size " << dataPacket.data.size() << " (" << soundPacketPtr->size << ") to " << dataPacket.host << std::endl;
    if (soundPacketPtr->magic != CorewarMagic) {
        std::cout << "Unidentified packet detected, ignoring..." << std::endl;
        return;
    }
    if (!this->timestamps.contains(dataPacket.host))
        this->timestamps[dataPacket.host] = 0;
    if (soundPacketPtr->timestamp < this->timestamps[dataPacket.host]) {
        std::cout << "Older sound packet recieved, ignoring..." << std::endl;
        return;
    }
    this->timestamps[dataPacket.host] = soundPacketPtr->timestamp;
    compressedBuffer.size = soundPacketPtr->size;
    compressedBuffer.samples.assign(soundPacketPtr->data, soundPacketPtr->data + soundPacketPtr->size);
    emit this->audioPacketRecieved(compressedBuffer, dataPacket.host);
}

#include "moc_AudioPacketSender.cpp"
