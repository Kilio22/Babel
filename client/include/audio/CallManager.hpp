/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** CallManager
*/

#ifndef CALLMANAGER_HPP_
#define CALLMANAGER_HPP_

#include "Audio.hpp"
#include "AudioCompressor.hpp"
#include "AudioManager.hpp"
#include "AudioPacketSender.hpp"

namespace Babel::Audio
{
    class CallManager : public QObject
    {
        Q_OBJECT

    public:
        CallManager();
        ~CallManager();

        void beginCall();
        void endCall();

    private slots:
        void onInputAvailable(const SoundBuffer &);
        void onOutputAvailable(const CompressedBuffer &);

    private:
        AudioManager audioManager;
        AudioPacketSender audioPacketSender;
        std::unique_ptr<IAudioCompressor> audioCompressor;
    };
}

#endif /* !CALLMANAGER_HPP_ */
