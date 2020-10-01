/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** AudioExtractor
*/

#ifndef AUDIOEXTRACTOR_HPP_
#define AUDIOEXTRACTOR_HPP_

#include "IAudioExtractor.hpp"
#include <opus.h>

namespace Babel::Client::Audio
{
    class AudioExtractor : public IAudioExtractor
    {
    public:
        AudioExtractor();
        ~AudioExtractor();

        SoundBuffer extractAudio(const CompressedBuffer &compressedBuffer) const override;

    private:
        OpusDecoder *decoder;
    };
}

#endif /* !AUDIOEXTRACTOR_HPP_ */
