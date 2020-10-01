/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioOutputDevice
*/

#ifndef AUDIOOUTPUTDEVICE_HPP_
#define AUDIOOUTPUTDEVICE_HPP_

#include "IAudioDevice.hpp"
#include <portaudio.h>
#include <queue>
#include <unordered_map>

namespace Babel::Client::Audio
{
    /**
     * @brief Implementation of IOutputDevice using portaudio library
     */
    class AudioOutputDevice : public IOutputDevice
    {
    public:
        AudioOutputDevice();
        ~AudioOutputDevice();

        void startStream() override;
        void stopStream() override;
        void setSound(const SoundBuffer &soundBuffer, const std::string &idFrom) override;

    private:
        static int callback(const void *, void *, unsigned long, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *);

    private:
        PaStream *stream;
        PaStreamParameters params;
        std::unordered_map<std::string, std::queue<SoundBuffer>> soundBuffers;
    };
}

#endif /* !AUDIOOUTPUTDEVICE_HPP_ */
