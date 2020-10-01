/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioExtractor
*/

#include "AudioExtractor.hpp"
#include "AudioException.hpp"
#include "opus.h"

Babel::Client::Audio::AudioExtractor::AudioExtractor()
    : decoder(NULL)
{
    int err;

    this->decoder = opus_decoder_create(Audio::SampleRate, Audio::ChannelCount, &err);
    if (err != OPUS_OK)
        throw Exceptions::AudioException("Could not create opus decoder.");
}

Babel::Client::Audio::AudioExtractor::~AudioExtractor()
{
    if (this->decoder)
        opus_decoder_destroy(this->decoder);
}

Babel::Client::Audio::SoundBuffer Babel::Client::Audio::AudioExtractor::extractAudio(const CompressedBuffer &cb) const
{
    SoundBuffer soundBuffer;
    int nDecode = opus_decode_float(this->decoder, cb.samples.data(), cb.size, soundBuffer.samples.data(), Audio::FramesPerBuffer, 0);

    if (nDecode < 0)
        throw Exceptions::AudioException("Could not extract audio.");
    return soundBuffer;
}
