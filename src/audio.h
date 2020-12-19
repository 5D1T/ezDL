#ifndef EZDL_AUDIO_H
#define EZDL_AUDIO_H

#include "error.h"
#include <cstddef>
#include <iostream>
#include <thread>


class EZDL_Audio
{
private:
    static void playSound(const char* path, size_t lenght)
    {
        SDL_AudioSpec soundSpec;
        Uint8 *soundBuffer;
        Uint32 soundLength = lenght;

        SDL_LoadWAV(path, &soundSpec, &soundBuffer, &soundLength);
        SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &soundSpec, NULL, 0);

        int a = SDL_QueueAudio(deviceId, soundBuffer, soundLength);
        SDL_PauseAudioDevice(deviceId, 0);
        SDL_Delay(lenght);

        EZDL_Assert(a);

        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(soundBuffer);
    }
    
public:
    void play(const char* path, size_t lenght)
    {
        std::thread t;
        t = std::thread(playSound, path, lenght);
        t.detach();
    }
};


#endif
