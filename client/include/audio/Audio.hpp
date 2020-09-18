/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <vector>

namespace Babel::Audio
{
    const int SampleRate = 44100;
    const int FramesPerBuffer = 512;
    const int ChannelCount = 2;

    struct SoundBuffer {
        int size;
        std::vector<float> samples;
    };
}

#endif /* !SOUND_HPP_ */
