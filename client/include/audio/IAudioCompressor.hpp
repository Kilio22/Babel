/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IAudioCompressor
*/

#ifndef IAUDIOCOMPRESSOR_HPP_
#define IAUDIOCOMPRESSOR_HPP_

#include "Audio.hpp"

namespace Babel::Audio
{
    class IAudioCompressor
    {
    public:
        virtual ~IAudioCompressor() = default;

        virtual CompressedBuffer compressAudio(const SoundBuffer &) const = 0;
        virtual SoundBuffer extractAudio(const CompressedBuffer &) const = 0;
    };
}

#endif /* !IAUDIOCOMPRESSOR_HPP_ */
