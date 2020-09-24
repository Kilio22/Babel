/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioCompressor
*/

#ifndef AUDIOCOMPRESSOR_HPP_
#define AUDIOCOMPRESSOR_HPP_

#include "Audio.hpp"
#include "IAudioCompressor.hpp"
#include <opus.h>

namespace Babel::Audio
{
    class AudioCompressor : public IAudioCompressor
    {
    public:
        AudioCompressor();
        ~AudioCompressor();

        CompressedBuffer compressAudio(const SoundBuffer &soundBuffer) override;
        SoundBuffer extractAudio(const CompressedBuffer &compressedBuffer) override;

    private:
        OpusDecoder *decoder;
        OpusEncoder *encoder;
    };
}

#endif /* !AUDIOCOMPRESSOR_HPP_ */
