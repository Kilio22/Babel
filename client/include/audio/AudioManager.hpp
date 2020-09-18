/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioManager
*/

#ifndef AUDIOMANAGER_HPP_
#define AUDIOMANAGER_HPP_

#include "Audio.hpp"
#include "IAudioDevice.hpp"
#include <QtCore/QObject>
#include <memory>

namespace Babel::Audio
{
    class AudioManager : public QObject
    {
        Q_OBJECT

    public:
        AudioManager();
        ~AudioManager();

        void startRecording();
        void stopRecording();
        void startListening();
        void stopListening();

    signals:
        void audioReady(const SoundBuffer &soundBuffer);

    private:
        std::unique_ptr<IAudioDevice> inputDevice;
        std::unique_ptr<IAudioDevice> outputDevice;
    };
}

#endif /* !AUDIOMANAGER_HPP_ */
