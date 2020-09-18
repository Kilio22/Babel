/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioInputDevice
*/

#ifndef AUDIOINPUTDEVICE_HPP_
#define AUDIOINPUTDEVICE_HPP_

#include "IAudioDevice.hpp"

namespace Babel::Audio
{
    class AudioInputDevice : public IAudioDevice
    {
    public:
        AudioInputDevice();
        ~AudioInputDevice() = default;

        void startStream() override;
        void stopStream() override;

    protected:
    private:
    };
}

#endif /* !AUDIOINPUTDEVICE_HPP_ */
