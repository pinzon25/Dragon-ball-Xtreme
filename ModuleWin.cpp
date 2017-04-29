#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleWin.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"



ModuleWin::ModuleWin()
{
	stage.x = 0;
	stage.y = 0;
	stage.w = SCREEN_WIDTH;
	stage.h = SCREEN_HEIGHT;
}

ModuleWin::~ModuleWin()
{}

// Load assets
bool ModuleWin::Start()
{

	App->render->camera.x = App->render->camera.y = 0;

	LOG("Loading space scene");

	background = App->textures->Load("dragonballxtreme/sayonara.png");




	return true;
}

// UnLoad assets
bool ModuleWin::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleWin::Update()
{
	App->render->Blit(background, 0, 0, &stage);

	return UPDATE_CONTINUE;
}