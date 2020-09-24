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
    if (Pa_CloseStream(this->stream) != paNoError)
        throw Client::Exceptions::AudioException("Could not close output stream.");
}

void Babel::Audio::AudioOutputDevice::setSound(const SoundBuffer &soundBuffer)
{
    this->soundBuffers.push(soundBuffer);
}

int Babel::Audio::AudioOutputDevice::callback(
    const void *, void *outputBuffer, unsigned long frameCount, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *data)
{
    AudioOutputDevice *_this = static_cast<AudioOutputDevice *>(data);

    if (_this->soundBuffers.empty())
        return paContinue;

    float *output = static_cast<float *>(outputBuffer);
    SoundBuffer &soundBuffer = _this->soundBuffers.front();

    std::memcpy(output, soundBuffer.samples.data(), Audio::ElementsPerBuffer * sizeof(float));
    _this->soundBuffers.pop();
    return paContinue;
}
