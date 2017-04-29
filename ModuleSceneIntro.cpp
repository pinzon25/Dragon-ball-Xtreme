#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "Module.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneIntro::ModuleSceneIntro()
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Desert intro");
	
	background = App->textures->Load("dragonballxtreme/welcomepage.png");
	
	

	App->render->camera.w = App->render->camera.h;
	
	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Desert scene");

	App->textures->Unload(background);
	
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if(App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->map);
	}

	return UPDATE_CONTINUE;
}