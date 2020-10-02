/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IAudioDevice
*/

#ifndef IAUDIODEVICE_HPP_
#define IAUDIODEVICE_HPP_

#include "Audio.hpp"

namespace Babel::Client::Audio
{
    /**
     * @brief Represents an audio device that can handle audio streams
     */
    class IAudioDevice
    {
    public:
        virtual ~IAudioDevice() = default;

        /**
         * @brief Starts the audio stream
         */
        virtual void startStream() = 0;

        /**
         * @brief Stop the audio stream
         */
        virtual void stopStream() = 0;
    };

    /**
     * @brief Represents an audio input device
     */
    class IInputDevice : public IAudioDevice
    {
    public:
        ~IInputDevice() override = default;

        /**
         * @brief Gets the SoundBuffer object resulting an audio input
         *
         * @return SoundBuffer object
         */
        virtual SoundBuffer getSound() = 0;
    };

    /**
     * @brief Represents an audio output device
     */
    class IOutputDevice : public IAudioDevice
    {
    public:
        ~IOutputDevice() override = default;

        /**
         * @brief Sets the SoundBuffer object for audio output
         *
         * @param soundBuffer SoundBuffer object
         * @param idFrom Id identifying audio origin (used for merging audio coming from multiple sources).
         */
        virtual void setSound(const SoundBuffer &soundBuffer, const std::string &idFrom) = 0;
    };

    /**
     * @brief Listener interface used to know when sound input is available.
     */
    class ISoundInputAvailableEventListener
    {
    public:
        virtual ~ISoundInputAvailableEventListener() = default;

        /**
         * @brief Called when sound input is available.
         */
        virtual void onSoundInputAvailable() = 0;
    };
}

#endif /* !IAUDIODEVICE_HPP_ */
