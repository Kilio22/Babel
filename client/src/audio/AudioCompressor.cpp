/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioCompressor
*/

#include "AudioCompressor.hpp"
#include "AudioException.hpp"
#include "opus.h"

Babel::Client::Audio::AudioCompressor::AudioCompressor()
    : encoder(NULL)
{
    int err;

    this->encoder = opus_encoder_create(Audio::SampleRate, Audio::ChannelCount, OPUS_APPLICATION_VOIP, &err);
    if (err != OPUS_OK)
        throw Exceptions::AudioException("Could not create opus encoder.");
}

Babel::Client::Audio::AudioCompressor::~AudioCompressor()
{
    if (this->encoder)
        opus_encoder_destroy(this->encoder);
}

Babel::Client::Audio::CompressedBuffer Babel::Client::Audio::AudioCompressor::compressAudio(const SoundBuffer &sb) const
{
    CompressedBuffer compressedBuffer;
    int nEncode = opus_encode_float(this->encoder, sb.samples.data(), Audio::FramesPerBuffer, compressedBuffer.samples.data(), Audio::ElementsPerBuffer);

    compressedBuffer.size = nEncode;
    if (nEncode < 0)
        throw Exceptions::AudioException("Could not compress audio.");
    return compressedBuffer;
}
