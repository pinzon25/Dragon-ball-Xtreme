#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleGameOver.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleSceneIntro.h"



ModuleGameOver::ModuleGameOver()
{
	stage.x = 0;
	stage.y = 0;
	stage.w = SCREEN_WIDTH;
	stage.h = SCREEN_HEIGHT;
}

ModuleGameOver::~ModuleGameOver()
{}

// Load assets
bool ModuleGameOver::Start()
{
	
	App->render->camera.x = App->render->camera.y = 0;

	LOG("Loading space scene");

	background = App->textures->Load("Gunsmoke/gameover.png");
	

	

	return true;
}

// UnLoad assets
bool ModuleGameOver::CleanUp()
{
	LOG("Unloading space scene");
	
	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleGameOver::Update()
{
	App->render->Blit(background, 0, 0, &stage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(this, App->scene_intro);
	}

	return UPDATE_CONTINUE;
}