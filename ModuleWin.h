#ifndef __MODULEWIN_H__
#define __MODULEWIN_H__

#include "Module.h"

struct SDL_Texture;

class ModuleWin : public Module
{
public:
	ModuleWin();
	~ModuleWin();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Rect stage;
	SDL_Texture* hud = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __MODULEWIN_H__

