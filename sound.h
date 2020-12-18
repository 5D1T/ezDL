#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include <iostream>
#include <thread>


class Sound
{
private:
    static void PlaySound(const char* path, int lenght)
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
    void Play(const char* path, int lenght)
    {
        thread t1;
        t1 = thread(PlaySound, path, lenght);
        t1.detach();
    }
};


#endif
