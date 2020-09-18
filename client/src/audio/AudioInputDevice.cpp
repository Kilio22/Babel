/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioInputDevice
*/

#include "AudioInputDevice.hpp"
#include "AudioException.hpp"
#include <iostream>

Babel::Audio::AudioInputDevice::AudioInputDevice()
    : streamOpened(false)
{
    this->params.device = Pa_GetDefaultInputDevice();
    if (this->params.device == paNoDevice) {
        throw Exceptions::AudioException("Could not find input device.");
    }
    this->params.channelCount = Audio::ChannelCount;
    this->params.sampleFormat = paFloat32;
    this->params.suggestedLatency = Pa_GetDeviceInfo(this->params.device)->defaultLowInputLatency;
    this->params.hostApiSpecificStreamInfo = NULL;
}

void Babel::Audio::AudioInputDevice::startStream()
{
    if (this->streamOpened)
        return;

    if (Pa_OpenStream(&this->stream, &this->params, NULL, Audio::SampleRate, Audio::FramesPerBuffer, paClipOff, AudioInputDevice::callback, this)
        != paNoError)
        throw Exceptions::AudioException("Could not open input stream.");

    if (Pa_StartStream(this->stream) != paNoError)
        throw Exceptions::AudioException("Could not start input stream.");

    std::cout << "Steaming input" << std::endl;
    this->streamOpened = true;
}

void Babel::Audio::AudioInputDevice::stopStream()
{
    if (!this->streamOpened)
        return;

    if (Pa_CloseStream(this->stream) != paNoError)
        throw Exceptions::AudioException("Could not close input stream.");

    std::cout << "Stopped streaming input" << std::endl;
    this->streamOpened = false;
}

int Babel::Audio::AudioInputDevice::callback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo *timeInfo,
    PaStreamCallbackFlags statusFlags, void *data)
{
    return paContinue;
}
