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
#include <cstdint>
#include <ctime>
#include <memory>

namespace Babel::Client::Audio
{
    class AudioPacketSender : public QObject
    {
        Q_OBJECT

    public:
        static const unsigned short DefaultAudioPort = 42424;
        static const int CorewarMagic = 0xea83f3;

#pragma pack(push, 1)
        struct SoundPacket {
            int magic = CorewarMagic;
            int64_t timestamp;
            int32_t size;
            char data[512 - sizeof(magic) - sizeof(timestamp) - sizeof(size)];
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
        void audioPacketRecieved(const CompressedBuffer &, const std::string &);

    private:
        std::unique_ptr<Network::IUdpClient> udpClient;
        std::vector<std::string> hosts;
        int64_t lastTimestamp;
    };
}

#endif /* !AUDIOPACKETSENDER_HPP_ */
