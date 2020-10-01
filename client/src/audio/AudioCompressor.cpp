/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioCompressor
*/

#include "AudioCompressor.hpp"
#include "AudioException.hpp"
#include "opus.h"
#include <iomanip>
#include <iostream>

Babel::Client::Audio::AudioCompressor::AudioCompressor()
    : decoder(NULL)
    , encoder(NULL)
    , mutex(std::make_unique<std::mutex>())
{
    int err;

    this->encoder = opus_encoder_create(Audio::SampleRate, Audio::ChannelCount, OPUS_APPLICATION_VOIP, &err);
    if (err != OPUS_OK)
        throw Exceptions::AudioException("Could not create opus encoder.");
    this->decoder = opus_decoder_create(Audio::SampleRate, Audio::ChannelCount, &err);
    if (err != OPUS_OK)
        throw Exceptions::AudioException("Could not create opus decoder.");
}

Babel::Client::Audio::AudioCompressor::~AudioCompressor()
{
    if (this->encoder)
        opus_encoder_destroy(this->encoder);
    if (this->decoder)
        opus_decoder_destroy(this->decoder);
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

Babel::Client::Audio::SoundBuffer Babel::Client::Audio::AudioCompressor::extractAudio(const CompressedBuffer &cb) const
{
    const std::lock_guard<std::mutex> guard(*this->mutex.get());
    SoundBuffer soundBuffer;
    int nDecode = opus_decode_float(this->decoder, cb.samples.data(), cb.size, soundBuffer.samples.data(), Audio::FramesPerBuffer, 0);

    if (nDecode < 0)
        throw Exceptions::AudioException("Could not extract audio.");
    return soundBuffer;
}
