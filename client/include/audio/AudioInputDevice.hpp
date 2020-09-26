/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioInputDevice
*/

#ifndef AUDIOINPUTDEVICE_HPP_
#define AUDIOINPUTDEVICE_HPP_

#include "IAudioDevice.hpp"
#include <portaudio.h>
#include <queue>

namespace Babel::Client::Audio
{
    class AudioInputDevice : public IInputDevice
    {
    public:
        AudioInputDevice(ISoundInputAvailableEventListener *listener);
        ~AudioInputDevice();

        void startStream() override;
        void stopStream() override;
        SoundBuffer getSound() override;

    private:
        static int callback(const void *, void *, unsigned long, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *);

    private:
        ISoundInputAvailableEventListener *listener;
        PaStream *stream;
        PaStreamParameters params;
        std::queue<SoundBuffer> soundBuffers;
    };
}

#endif /* !AUDIOINPUTDEVICE_HPP_ */
