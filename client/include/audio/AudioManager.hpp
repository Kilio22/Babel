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
    class AudioManager : public QObject, public ISoundInputAvailableEventListener
    {
        Q_OBJECT

    public:
        AudioManager();
        ~AudioManager();

        void onSoundInputAvailable() override;

        void startRecording();
        void stopRecording();
        void startSpeaking();
        void stopSpeaking();
        void queueAudio(const SoundBuffer &);

    signals:
        void inputAvailable(const SoundBuffer &);

    private:
        std::unique_ptr<IInputDevice> inputDevice;
        std::unique_ptr<IOutputDevice> outputDevice;
    };
}

#endif /* !AUDIOMANAGER_HPP_ */
