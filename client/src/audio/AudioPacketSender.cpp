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
    Client::Network::IUdpClient::DataPacket dataPacket;
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

void Babel::Audio::AudioPacketSender::onDataAvailable()
{
    CompressedBuffer compressedBuffer;
    Client::Network::IUdpClient::DataPacket dataPacket = this->udpClient->getData();
    SoundPacket *packetDataPtr = reinterpret_cast<SoundPacket *>(dataPacket.data.data());

    compressedBuffer.size = packetDataPtr->size;
    compressedBuffer.samples.assign(packetDataPtr->data, packetDataPtr->data + packetDataPtr->size);
    std::cout << "Recieved packet of size " << dataPacket.data.size() << " from " << dataPacket.host << std::endl;
    emit this->audioPacketRecieved(compressedBuffer, dataPacket.host);
}

#include "moc_AudioPacketSender.cpp"
