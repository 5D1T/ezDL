/*
** sound.h
** Wrapper for SDL's audio manipulation, allowing much easier use
*/


#ifndef EZDL_SOUND_H
#define EZDL_SOUND_H

#include <iostream>
#include <thread>


class Sound
{
private:
    static void playSound(const char* path, int lenght)
    {
        SDL_AudioSpec soundSpec;
        Uint8 *soundBuffer;
        Uint32 soundLength;
        soundLength = lenght;

        SDL_LoadWAV(path, &soundSpec, &soundBuffer, &soundLength);

        SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &soundSpec, NULL, 0);

        int a = SDL_QueueAudio(deviceId, soundBuffer, soundLength);
        SDL_PauseAudioDevice(deviceId, 0);
        SDL_Delay(lenght);

        if (!a)
        {
            std::cout << SDL_GetError() << std::endl;
        }
        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(soundBuffer);
    }
public:
    void play(const char* path, int lenght)
    {
        std::thread t;
        t = thread(playSound, path, lenght);
        t.detach();
    }
};


#endif
