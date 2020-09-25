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

Babel::Audio::AudioCompressor::AudioCompressor()
    : decoder(NULL)
    , encoder(NULL)
{
    int err;

    this->encoder = opus_encoder_create(Audio::SampleRate, Audio::ChannelCount, OPUS_APPLICATION_VOIP, &err);
    if (err != OPUS_OK)
        throw Client::Exceptions::AudioException("Could not create opus encoder.");
    this->decoder = opus_decoder_create(Audio::SampleRate, Audio::ChannelCount, &err);
    if (err != OPUS_OK)
        throw Client::Exceptions::AudioException("Could not create opus decoder.");
}

Babel::Audio::AudioCompressor::~AudioCompressor()
{
    if (this->encoder)
        opus_encoder_destroy(this->encoder);
    if (this->decoder)
        opus_decoder_destroy(this->decoder);
}

Babel::Audio::CompressedBuffer Babel::Audio::AudioCompressor::compressAudio(const SoundBuffer &sb) const
{
    CompressedBuffer compressedBuffer;
    int nEncode = opus_encode_float(this->encoder, sb.samples.data(), Audio::FramesPerBuffer, compressedBuffer.samples.data(), sb.samples.size());

    compressedBuffer.size = nEncode;
    if (nEncode < 0)
        throw Client::Exceptions::AudioException("Could not compress audio.");
    return compressedBuffer;
}

Babel::Audio::SoundBuffer Babel::Audio::AudioCompressor::extractAudio(const CompressedBuffer &cb) const
{
    SoundBuffer soundBuffer;
    int nDecode = opus_decode_float(this->decoder, cb.samples.data(), cb.size, soundBuffer.samples.data(), Audio::FramesPerBuffer, 0);

    if (nDecode < 0)
        throw Client::Exceptions::AudioException("Could not extract audio.");
    return soundBuffer;
}
