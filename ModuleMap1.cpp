#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleMap1.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleGameOver.h"


ModuleMap1::ModuleMap1()
{
	stage.x = 0;
	stage.y = 0;
	stage.w = SCREEN_WIDTH;
	stage.h = SCREEN_HEIGHT;
}

ModuleMap1::~ModuleMap1()
{}

// Load assets
bool ModuleMap1::Start()
{
	
	

	LOG("Loading Ice scene");
	
	background = App->textures->Load("dragonballxtreme/desert1.png");
	App->audio->musicLoad("dragonballxtreme/theme18.ogg");

	App->collision->Enable();
	App->player->Enable();
	App->particles->Enable();

	App->enemies->Enable();
	App->audio->Enable();

	
	return true;
}

// UnLoad assets
bool ModuleMap1::CleanUp()
{
	LOG("Unloading Ice scene");

 	App->textures->Unload(background);

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleMap1::Update()
{
	
	

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	
	return UPDATE_CONTINUE;
}