/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioInputDevice
*/

#ifndef AUDIOINPUTDEVICE_HPP_
#define AUDIOINPUTDEVICE_HPP_

#include "Audio.hpp"
#include "IAudioDevice.hpp"
#include "portaudio.h"

namespace Babel::Audio
{
    class AudioInputDevice : public IAudioDevice
    {
    public:
        AudioInputDevice();
        ~AudioInputDevice() = default;

        void startStream() override;
        void stopStream() override;

        static int callback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo *timeInfo,
            PaStreamCallbackFlags statusFlags, void *data);

    private:
        PaStream *stream;
        PaStreamParameters params;
        bool streamOpened;
        std::vector<SoundBuffer> soundBuffers;
    };
}

#endif /* !AUDIOINPUTDEVICE_HPP_ */
