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

namespace Babel::Audio
{
    class AudioOutputDevice : public IOutputDevice
    {
    public:
        AudioOutputDevice();
        ~AudioOutputDevice();

        void startStream() override;
        void stopStream() override;
        void setSound(const SoundBuffer &soundBuffer) override;

    private:
        static int callback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo *timeInfo,
            PaStreamCallbackFlags statusFlags, void *data);

    private:
        PaStream *stream;
        PaStreamParameters params;
        std::queue<SoundBuffer> soundBuffers;
    };
}

#endif /* !AUDIOOUTPUTDEVICE_HPP_ */
