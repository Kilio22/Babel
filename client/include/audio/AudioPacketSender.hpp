/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioPacketSender
*/

#ifndef AUDIOPACKETSENDER_HPP_
#define AUDIOPACKETSENDER_HPP_

#include "Audio.hpp"
#include "IUdpClient.hpp"
#include <QtCore/QObject>
#include <memory>

namespace Babel::Audio
{
    class AudioPacketSender : public QObject
    {
        Q_OBJECT

    public:
        const unsigned short DefaultAudioPort = 42424;

#pragma pack(push, 1)
        struct SoundPacket {
            long size;
            char data[512 - sizeof(size)];
        };
#pragma pack(pop)

    public:
        AudioPacketSender();
        ~AudioPacketSender() = default;

        void connectTo(const std::vector<std::string> &hosts);
        void sendAudio(const CompressedBuffer &compressedBuffer);

    private slots:
        void onDataAvailable();

    signals:
        void audioPacketRecieved(const CompressedBuffer &);

    private:
        std::unique_ptr<Client::Network::IUdpClient> udpClient;
        std::vector<std::string> hosts;
    };
}

#endif /* !AUDIOPACKETSENDER_HPP_ */