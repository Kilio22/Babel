/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioManager
*/

#ifndef AUDIOMANAGER_HPP_
#define AUDIOMANAGER_HPP_

#include "Audio.hpp"
#include "AudioCompressor.hpp"
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
        void queueAudio(const CompressedBuffer &soundBuffer, const std::string &hostFrom) const;

    signals:
        void inputAvailable(const CompressedBuffer &);

    private:
        std::unique_ptr<IInputDevice> inputDevice;
        std::unique_ptr<IOutputDevice> outputDevice;
        std::unique_ptr<IAudioCompressor> audioCompressor;
    };
}

#endif /* !AUDIOMANAGER_HPP_ */
