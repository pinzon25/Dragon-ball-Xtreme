#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "Globals.h"

#define Musictime 2.0f
#define MAX_EFFECT 200

class ModuleAudio : public Module
{
public:

	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	bool musicLoad(const char* path, float time = Musictime);
	bool Playeffect(uint effect, int repeat = 0);
	uint Loadeffect(const char* path);
	bool unloadeffect(uint id);
	bool ModuleAudio::StopMusic();


private:
	Mix_Music* music = nullptr;
	Mix_Chunk* shoot[MAX_EFFECT];
	uint lasteffect = 1;
};
#endif 
