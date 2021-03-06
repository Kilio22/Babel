/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <QtCore/QMetaType>
#include <array>
#include <cstring>
#include <vector>
#include <cstdint>

namespace Babel::Client::Audio
{
    const int SampleRate = 48000;
    const int FramesPerBuffer = 480;
    const int ChannelCount = 2;
    const int ElementsPerBuffer = FramesPerBuffer * ChannelCount;

    struct SoundBuffer {
        SoundBuffer() : samples({})
        {
            this->samples.fill(0);
        }

        SoundBuffer(const float *begin)
        {
            std::memcpy(samples.data(), begin, ElementsPerBuffer * sizeof(float));
        }

        std::array<float, ElementsPerBuffer> samples;
    };

    struct CompressedBuffer {
        CompressedBuffer()
        {
            this->samples.resize(ElementsPerBuffer);
            std::fill(this->samples.begin(), this->samples.end(), 0);
        }

        std::vector<unsigned char> samples;
        int32_t size;
    };
}

Q_DECLARE_METATYPE(Babel::Client::Audio::SoundBuffer)

#endif /* !SOUND_HPP_ */
