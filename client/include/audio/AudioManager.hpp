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

namespace Babel::Client::Audio
{
    class AudioManager : public QObject, public ISoundInputAvailableEventListener
    {
        Q_OBJECT

    public:
        AudioManager();
        ~AudioManager() = default;

        void onSoundInputAvailable() override;

        void startRecording() const;
        void stopRecording() const;
        void startSpeaking() const;
        void stopSpeaking() const;
        void queueAudio(const SoundBuffer &soundBuffer, const std::string &hostFrom) const;

    signals:
        void inputAvailable(const SoundBuffer &);

    private:
        std::unique_ptr<IInputDevice> inputDevice;
        std::unique_ptr<IOutputDevice> outputDevice;
    };
}

#endif /* !AUDIOMANAGER_HPP_ */
