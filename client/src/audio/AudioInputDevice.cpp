/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioInputDevice
*/

#include "AudioInputDevice.hpp"
#include "AudioException.hpp"
#include <iostream>
#include <iomanip>

Babel::Audio::AudioInputDevice::AudioInputDevice(ISoundInputAvailableEventListener *listener)
    : listener(listener)
{
    this->params.device = Pa_GetDefaultInputDevice();
    if (this->params.device == paNoDevice) {
        throw Client::Exceptions::AudioException("Could not find input device.");
    }
    this->params.channelCount = Audio::ChannelCount;
    this->params.sampleFormat = paFloat32;
    this->params.suggestedLatency = Pa_GetDeviceInfo(this->params.device)->defaultLowInputLatency;
    this->params.hostApiSpecificStreamInfo = NULL;
}

Babel::Audio::AudioInputDevice::~AudioInputDevice()
{
    if (!Pa_IsStreamStopped(this->stream))
        Pa_CloseStream(this->stream);
}

void Babel::Audio::AudioInputDevice::startStream()
{
    if (Pa_OpenStream(&this->stream, &this->params, NULL, Audio::SampleRate, Audio::FramesPerBuffer, paClipOff, AudioInputDevice::callback, this)
        != paNoError)
        throw Client::Exceptions::AudioException("Could not open input stream.");

    if (Pa_StartStream(this->stream) != paNoError)
        throw Client::Exceptions::AudioException("Could not start input stream.");

    std::cout << "Steaming input." << std::endl;
}

void Babel::Audio::AudioInputDevice::stopStream()
{
    if (Pa_CloseStream(this->stream) != paNoError)
        throw Client::Exceptions::AudioException("Could not close input stream.");

    std::cout << "Stopped streaming input." << std::endl;
}

Babel::Audio::SoundBuffer Babel::Audio::AudioInputDevice::getSound()
{
    auto top = this->soundBuffers.front();

    this->soundBuffers.pop();
    return top;
}

int Babel::Audio::AudioInputDevice::callback(
    const void *inputBuffer, void *, unsigned long frameCount, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *data)
{
    AudioInputDevice *_this = static_cast<AudioInputDevice *>(data);
    const float *input = static_cast<const float *>(inputBuffer);

    (void)frameCount;

    if (!_this->soundBuffers.empty())
        return paContinue;
    _this->soundBuffers.push({ input });
    _this->listener->onSoundInputAvailable();
    return paContinue;
}
