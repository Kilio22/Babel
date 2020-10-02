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

namespace Babel::Client::Audio
{
    class CallManager : public QObject
    {
        Q_OBJECT

    public:
        CallManager();
        ~CallManager() = default;

        void beginCall(const std::vector<std::string> &hosts);
        void endCall();

    private slots:
        void onInputAvailable(const CompressedBuffer &);
        void onOutputAvailable(const CompressedBuffer &, const std::string &);

    private:
        AudioManager audioManager;
        AudioPacketSender audioPacketSender;
        bool inCall;
    };
}

#endif /* !CALLMANAGER_HPP_ */
