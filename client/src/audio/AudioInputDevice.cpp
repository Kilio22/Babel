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

Babel::Client::Audio::AudioInputDevice::AudioInputDevice(ISoundInputAvailableEventListener *listener)
    : listener(listener)
{
    auto err = Pa_Initialize();

    if (err != paNoError)
        throw Exceptions::AudioException(Pa_GetErrorText(err));

    this->params.device = Pa_GetDefaultInputDevice();
    if (this->params.device == paNoDevice)
        throw Exceptions::AudioException("Could not find input device.");
    this->params.channelCount = Audio::ChannelCount;
    this->params.sampleFormat = paFloat32;
    this->params.suggestedLatency = Pa_GetDeviceInfo(this->params.device)->defaultLowInputLatency;
    this->params.hostApiSpecificStreamInfo = NULL;
}

Babel::Client::Audio::AudioInputDevice::~AudioInputDevice()
{
    if (!Pa_IsStreamStopped(this->stream))
        Pa_CloseStream(this->stream);
    Pa_Terminate();
}

void Babel::Client::Audio::AudioInputDevice::startStream()
{
    if (Pa_OpenStream(&this->stream, &this->params, NULL, Audio::SampleRate, Audio::FramesPerBuffer, paClipOff, AudioInputDevice::callback, this)
        != paNoError)
        throw Exceptions::AudioException("Could not open input stream.");

    if (Pa_StartStream(this->stream) != paNoError)
        throw Exceptions::AudioException("Could not start input stream.");

    std::cout << "Steaming input." << std::endl;
}

void Babel::Client::Audio::AudioInputDevice::stopStream()
{
    if (Pa_CloseStream(this->stream) != paNoError)
        throw Exceptions::AudioException("Could not close input stream.");

    std::cout << "Stopped streaming input." << std::endl;
}

Babel::Client::Audio::SoundBuffer Babel::Client::Audio::AudioInputDevice::getSound()
{
    auto top = this->soundBuffers.front();

    this->soundBuffers.pop();
    return top;
}

int Babel::Client::Audio::AudioInputDevice::callback(
    const void *inputBuffer, void *, uint64_t frameCount, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *data)
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
