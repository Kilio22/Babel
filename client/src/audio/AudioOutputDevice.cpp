/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioOutputDevice
*/

#include "AudioOutputDevice.hpp"
#include "AudioException.hpp"
#include <iostream>

Babel::Client::Audio::AudioOutputDevice::AudioOutputDevice()
    : stream(nullptr)
{
    auto err = Pa_Initialize();

    if (err != paNoError)
        throw Exceptions::AudioException(Pa_GetErrorText(err));

    this->params.device = Pa_GetDefaultOutputDevice();
    if (this->params.device == paNoDevice)
        throw Exceptions::AudioException("Could not find input device.");
    this->params.channelCount = Audio::ChannelCount;
    this->params.sampleFormat = paFloat32;
    this->params.suggestedLatency = Pa_GetDeviceInfo(this->params.device)->defaultLowOutputLatency;
    this->params.hostApiSpecificStreamInfo = nullptr;
}

Babel::Client::Audio::AudioOutputDevice::~AudioOutputDevice()
{
    if (!Pa_IsStreamStopped(this->stream))
        Pa_CloseStream(this->stream);
    Pa_Terminate();
}

void Babel::Client::Audio::AudioOutputDevice::startStream()
{
    if (Pa_OpenStream(&this->stream, nullptr, &this->params, Audio::SampleRate, Audio::FramesPerBuffer, paClipOff, AudioOutputDevice::callback, this)
        != paNoError)
        throw Exceptions::AudioException("Could not open output stream.");
    if (Pa_StartStream(this->stream) != paNoError)
        throw Exceptions::AudioException("Could not start output stream.");
    std::cout << "Steaming output." << std::endl;
}

void Babel::Client::Audio::AudioOutputDevice::stopStream()
{
    this->soundBuffers.clear();
    if (Pa_CloseStream(this->stream) != paNoError)
        throw Exceptions::AudioException("Could not close output stream.");
    std::cout << "Stopped streaming input." << std::endl;
}

void Babel::Client::Audio::AudioOutputDevice::setSound(const SoundBuffer &soundBuffer, const std::string &idFrom)
{
    this->soundBuffers[idFrom].push(soundBuffer);
}

int Babel::Client::Audio::AudioOutputDevice::callback(
    const void *, void *outputBuffer, unsigned long, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *data)
{
    auto _this = static_cast<AudioOutputDevice *>(data);
    auto output = static_cast<float *>(outputBuffer);

    std::memset(output, 0, Audio::ElementsPerBuffer * sizeof(float));
    for (auto it = _this->soundBuffers.begin(); it != _this->soundBuffers.end();) {
        auto &pair = *it;

        ++it;
        if (pair.second.empty()) {
            _this->soundBuffers.erase(pair.first);
            continue;
        }

        auto &soundBuffer = pair.second.front();

        for (int i = 0; i < Audio::ElementsPerBuffer; ++i) {
            output[i] += soundBuffer.samples[i];
        }
        pair.second.pop();
    }
    return paContinue;
}
