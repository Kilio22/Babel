/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IAudioDevice
*/

#ifndef IAUDIODEVICE_HPP_
#define IAUDIODEVICE_HPP_

namespace Babel::Audio
{
    class IAudioDevice
    {
    public:
        virtual ~IAudioDevice() = default;

        virtual void startStream() = 0;
        virtual void stopStream() = 0;
    };
}

#endif /* !IAUDIODEVICE_HPP_ */
