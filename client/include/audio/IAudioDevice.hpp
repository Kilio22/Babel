/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IAudioDevice
*/

#ifndef IAUDIODEVICE_HPP_
#define IAUDIODEVICE_HPP_

#include "Audio.hpp"
#include <QtPlugin>

namespace Babel::Audio
{
    class IAudioDevice
    {
    public:
        virtual ~IAudioDevice() = default;

        virtual void startStream() = 0;
        virtual void stopStream() = 0;
    };

    class IInputDevice : public IAudioDevice
    {
    public:
        virtual ~IInputDevice() = default;

        virtual SoundBuffer getSound() = 0;
    };

    class IOutputDevice : public IAudioDevice
    {
    public:
        virtual ~IOutputDevice() = default;

        virtual void setSound(const SoundBuffer &) = 0;
    };

    class ISoundInputAvailableEventListener
    {
    public:
        virtual ~ISoundInputAvailableEventListener() = default;

        virtual void onSoundInputAvailable() = 0;
    };
}

#endif /* !IAUDIODEVICE_HPP_ */
