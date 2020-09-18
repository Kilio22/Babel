/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioOutputDevice
*/

#ifndef AUDIOOUTPUTDEVICE_HPP_
#define AUDIOOUTPUTDEVICE_HPP_

#include "IAudioDevice.hpp"

namespace Babel::Audio
{
    class AudioOutputDevice : public IAudioDevice
    {
    public:
        AudioOutputDevice();
        ~AudioOutputDevice() = default;

        void startStream() override;
        void stopStream() override;

    protected:
    private:
    };
}

#endif /* !AUDIOOUTPUTDEVICE_HPP_ */
