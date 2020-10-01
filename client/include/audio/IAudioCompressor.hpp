/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** IAudioCompressor
*/

#ifndef IAUDIOCOMPRESSOR_HPP_
#define IAUDIOCOMPRESSOR_HPP_

#include "Audio.hpp"

namespace Babel::Client::Audio
{
    class IAudioCompressor
    {
    public:
        virtual ~IAudioCompressor() = default;

        virtual CompressedBuffer compressAudio(const SoundBuffer &) const = 0;
    };
}

#endif /* !IAUDIOCOMPRESSOR_HPP_ */
