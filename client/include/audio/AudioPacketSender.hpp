/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioPacketSender
*/

#ifndef AUDIOPACKETSENDER_HPP_
#define AUDIOPACKETSENDER_HPP_

#include "Audio.hpp"
#include <QtCore/QObject>

namespace Babel::Audio
{
    class AudioPacketSender : public QObject
    {
        Q_OBJECT

    public:
        AudioPacketSender();
        ~AudioPacketSender();

        void sendAudio(const CompressedBuffer &compressedBuffer);

    signals:
        void audioPacketRecieved(const CompressedBuffer &);

    private:
        void recieveAudioTmp(const CompressedBuffer &compressedBuffer);
    };
}

#endif /* !AUDIOPACKETSENDER_HPP_ */
