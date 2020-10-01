/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IAudioExtractor
*/

#ifndef IAUDIOEXTRACTOR_HPP_
#define IAUDIOEXTRACTOR_HPP_

#include "Audio.hpp"

namespace Babel::Client::Audio
{
    class IAudioExtractor
    {
    public:
        virtual ~IAudioExtractor() = default;

        virtual SoundBuffer extractAudio(const CompressedBuffer &) const = 0;
    };
}

#endif /* !IAUDIOEXTRACTOR_HPP_ */
