/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioOutputDevice
*/

#include "AudioOutputDevice.hpp"
#include "AudioException.hpp"
#include <iostream>

Babel::Audio::AudioOutputDevice::AudioOutputDevice()
{
    auto err = Pa_Initialize();

    if (err != paNoError)
        throw Client::Exceptions::AudioException(Pa_GetErrorText(err));

    this->params.device = Pa_GetDefaultOutputDevice();
    if (this->params.device == paNoDevice) {
        throw Client::Exceptions::AudioException("Could not find input device.");
    }
    this->params.channelCount = Audio::ChannelCount;
    this->params.sampleFormat = paFloat32;
    this->params.suggestedLatency = Pa_GetDeviceInfo(this->params.device)->defaultLowOutputLatency;
    this->params.hostApiSpecificStreamInfo = NULL;
}

Babel::Audio::AudioOutputDevice::~AudioOutputDevice()
{
    if (!Pa_IsStreamStopped(this->stream))
        Pa_CloseStream(this->stream);
    Pa_Terminate();
}

void Babel::Audio::AudioOutputDevice::startStream()
{
    if (Pa_OpenStream(&this->stream, NULL, &this->params, Audio::SampleRate, Audio::FramesPerBuffer, paClipOff, AudioOutputDevice::callback, this)
        != paNoError)
        throw Client::Exceptions::AudioException("Could not open output stream.");
    if (Pa_StartStream(this->stream) != paNoError)
        throw Client::Exceptions::AudioException("Could not start output stream.");
}

void Babel::Audio::AudioOutputDevice::stopStream()
{
    this->soundBuffers.clear();
    if (Pa_CloseStream(this->stream) != paNoError)
        throw Client::Exceptions::AudioException("Could not close output stream.");
}

void Babel::Audio::AudioOutputDevice::setSound(const SoundBuffer &soundBuffer, const std::string &idFrom)
{
    this->soundBuffers[idFrom].push(soundBuffer);
}

int Babel::Audio::AudioOutputDevice::callback(
    const void *, void *outputBuffer, unsigned long frameCount, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *data)
{
    AudioOutputDevice *_this = static_cast<AudioOutputDevice *>(data);
    float *output = static_cast<float *>(outputBuffer);

    std::memset(output, 0, Audio::ElementsPerBuffer * sizeof(float));
    if (_this->soundQueuesEmpty())
        return paContinue;

    SoundBuffer &soundBuffer = _this->soundBuffers.begin()->second.front();
    for (auto &pair : _this->soundBuffers) {
        if (pair.second.empty())
            continue;

        auto &soundBuffer = pair.second.front();

        for (int i = 0; i < Audio::ElementsPerBuffer; ++i)
            output[i] += soundBuffer.samples[i];
        pair.second.pop();
    }
    return paContinue;
}

bool Babel::Audio::AudioOutputDevice::soundQueuesEmpty() const
{
    for (auto &pair : this->soundBuffers) {
        if (pair.second.empty() == false)
            return false;
    }
    return true;
}
