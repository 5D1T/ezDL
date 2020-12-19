#ifndef EZDL_AUDIO_H
#define EZDL_AUDIO_H

#include <cstddef>
#include <thread>


class EZDL_Audio
{
private:
    size_t m_length;
    const char* m_path;

    static void playSound(const char* path, size_t length)
    {
	    SDL_AudioSpec soundSpec;
	    Uint8 *soundBuffer;
	    Uint32 soundLength = length;

	    SDL_LoadWAV(path, &soundSpec, &soundBuffer, &soundLength);
	    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &soundSpec, NULL, 0);

	    int a = SDL_QueueAudio(deviceId, soundBuffer, soundLength);
	    SDL_PauseAudioDevice(deviceId, 0);
	    SDL_Delay(length);

	    EZDL_Assert(a);

	    SDL_CloseAudioDevice(deviceId);
	    SDL_FreeWAV(soundBuffer);
	}
    
public:
    EZDL_Audio(const char* path, size_t length)
    {
		m_path = path;
		m_length = length;
	}

    void play()
	{
	    std::thread t;
	    t = std::thread(playSound, m_path, m_length);
	    t.detach();
	}
};


#endif
