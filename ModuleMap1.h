#ifndef __MODULEMAP1_H__
#define __MODULEMAP1_H__

#include "Module.h"

struct SDL_Texture;

class ModuleMap1 : public Module
{
public:
	ModuleMap1();
	~ModuleMap1();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* background = nullptr;
	SDL_Rect stage;
	SDL_Texture* hud = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __MODULEMAP1_H__