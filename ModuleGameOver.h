#ifndef __MODULEGAMEOVER_H__
#define __MODULEGAMEOVER_H__

#include "Module.h"

struct SDL_Texture;

class ModuleGameOver : public Module
{
public:
	ModuleGameOver();
	~ModuleGameOver();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Rect stage;
	SDL_Texture* hud = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __MODULEGAMEOVER_H__
