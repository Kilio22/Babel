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
    : udpClient(std::make_unique<QtUdpClient>())
{
    auto newClient = new QtUdpClient();

    QObject::connect(newClient, &QtUdpClient::dataAvailable, this, &AudioPacketSender::onDataAvailable);
    this->udpClient.reset(newClient);
}

void Babel::Client::Audio::AudioPacketSender::connectTo(const std::vector<std::string> &hosts)
{
    this->hosts = hosts;
    this->udpClient->connect(DefaultAudioPort);
}

void Babel::Client::Audio::AudioPacketSender::sendAudio(const CompressedBuffer &compressedBuffer)
{
    IUdpClient::DataPacket dataPacket;
    SoundPacket soundPacket = {};
    char *ptr;

    dataPacket.port = DefaultAudioPort;

    soundPacket.size = compressedBuffer.size;
    std::memcpy(soundPacket.data, compressedBuffer.samples.data(), compressedBuffer.size);
    ptr = reinterpret_cast<char *>(&soundPacket);

    dataPacket.data.assign(ptr, ptr + sizeof(SoundPacket));
    for (auto &host : this->hosts) {
        dataPacket.host = host;
        std::cout << "Sending packet of size " << dataPacket.data.size() << " to " << dataPacket.host << std::endl;
        this->udpClient->send(dataPacket);
    }
}

void Babel::Client::Audio::AudioPacketSender::onDataAvailable()
{
    CompressedBuffer compressedBuffer;
    IUdpClient::DataPacket dataPacket = this->udpClient->getData();
    SoundPacket *packetDataPtr = reinterpret_cast<SoundPacket *>(dataPacket.data.data());

    compressedBuffer.size = packetDataPtr->size;
    compressedBuffer.samples.assign(packetDataPtr->data, packetDataPtr->data + packetDataPtr->size);
    std::cout << "Recieved packet of size " << dataPacket.data.size() << " from " << dataPacket.host << std::endl;
    emit this->audioPacketRecieved(compressedBuffer, dataPacket.host);
}

#include "moc_AudioPacketSender.cpp"
