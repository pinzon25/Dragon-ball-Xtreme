#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_GunMen.h"
#include "Enemy_Backstabber.h"
#include "Enemy_Bomber.h"
#include "Enemy_WindowSniperRight.h"
#include "Enemy_WindowSniperLeft.h"
#include "Enemy_RiffleMen.h"
#include "Enemy_PowerUp.h"
#include "Enemy_Barrel.h"
#include "Enemy_GunMenJumper.h"
#include "Enemy_GunMenBalcony.h"
#include "Enemy_GunMenLeft.h"
#include "Enemy_GunMenRight.h"

#define SPAWN_MARGIN 70

ModuleEnemies::ModuleEnemies()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("Gunsmoke/EnemySprites.png");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if ((queue[i].type == ENEMY_TYPES::GUNMEN)
				|| (queue[i].type == ENEMY_TYPES::BARREL)
				|| (queue[i].type == ENEMY_TYPES::BOMBER)
				|| (queue[i].type == ENEMY_TYPES::RIFFLEMEN)
				|| (queue[i].type == ENEMY_TYPES::GUNMEN)
				|| (queue[i].type == ENEMY_TYPES::GUNMENBALCONY))
			{
				if (queue[i].y > (abs(App->render->camera.y) / SCREEN_SIZE) - SPAWN_MARGIN)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			if ((queue[i].type == ENEMY_TYPES::BACKSTABBER)
				|| (queue[i].type == ENEMY_TYPES::GUNMENJUMPER)
				|| (queue[i].type == ENEMY_TYPES::GUNMENLEFT)
				|| (queue[i].type == ENEMY_TYPES::GUNMENRIGHT))
			{
				if (queue[i].y > (abs(App->render->camera.y) / SCREEN_SIZE) + 70)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			if ((queue[i].type == ENEMY_TYPES::WINDOWSNIPERLEFT)
				|| (queue[i].type == ENEMY_TYPES::WINDOWSNIPERRIGHT))
			{
				if (queue[i].y > (abs(App->render->camera.y) / SCREEN_SIZE) + 20)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		if(enemies[i] != nullptr) enemies[i]->Move();

	for(uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) {
			enemies[i]->Draw(sprites);
			enemies[i]->Shoot(); 
		
		}

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			if (enemies[i]->position.y>((abs(App->render->camera.y) + SCREEN_WIDTH) / SCREEN_SIZE) + 240)
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for(; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if(i != MAX_ENEMIES)
	{
		switch(info.type)
		{
			case ENEMY_TYPES::GUNMEN:
			enemies[i] = new Enemy_GunMen(info.x,info.y);
			enemies[i]->type = ENEMY_TYPES::GUNMEN;
			break;
			case ENEMY_TYPES::BACKSTABBER:
			enemies[i] = new Enemy_BackStabber(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BACKSTABBER;
			break;
			case ENEMY_TYPES::WINDOWSNIPERLEFT:
			enemies[i] = new Enemy_WindowSniperLeft(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::WINDOWSNIPERLEFT;
			break;
			case ENEMY_TYPES::WINDOWSNIPERRIGHT:
			enemies[i] = new Enemy_WindowSniperRight(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::WINDOWSNIPERRIGHT;
			break;
			case ENEMY_TYPES::BOMBER:
			enemies[i] = new Enemy_Bomber(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BOMBER;
			break;
			case ENEMY_TYPES::RIFFLEMEN:
			enemies[i] = new Enemy_RiffleMen(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::RIFFLEMEN;
			break;
			case ENEMY_TYPES::BARREL:
			enemies[i] = new Enemy_Barrel(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BARREL;
			break;
			case ENEMY_TYPES::GUNMENJUMPER:
				enemies[i] = new Enemy_GunMenJumper(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::GUNMENJUMPER;
				break;
			case ENEMY_TYPES::GUNMENBALCONY:
				enemies[i] = new Enemy_GunMenBalcony(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::GUNMENBALCONY;
				break;
			case ENEMY_TYPES::GUNMENLEFT:
				enemies[i] = new Enemy_GunMenBalcony(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::GUNMENLEFT;
				break;
			case ENEMY_TYPES::GUNMENRIGHT:
				enemies[i] = new Enemy_GunMenBalcony(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::GUNMENRIGHT;
				break;
			/*case ENEMY_TYPES::POWERUP:
				enemies[i] = new Enemy_PowerUp(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::POWERUP;
			break;*/
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1 && c2->type==COLLIDER_PLAYER_SHOT||c2->type==COLLIDER_PLAYER)
		{

			enemies[i]->OnCollision(c2);
			if ((enemies[i]->type == ENEMY_TYPES::GUNMEN)
				|| (enemies[i]->type == ENEMY_TYPES::GUNMENJUMPER)
				|| (enemies[i]->type == ENEMY_TYPES::GUNMENLEFT)
				|| (enemies[i]->type == ENEMY_TYPES::GUNMENRIGHT)
				|| (enemies[i]->type == ENEMY_TYPES::GUNMENBALCONY))
			{
				App->particles->AddParticle(App->particles->deadGunMen, c1->rect.x, c1->rect.y, COLLIDER_NONE);

				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			if (enemies[i]->type==ENEMY_TYPES::WINDOWSNIPERRIGHT) 
			{
					App->particles->AddParticle(App->particles->deadWindowSniperRight, c1->rect.x, c1->rect.y, COLLIDER_NONE);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
			}
			if(enemies[i]->type == ENEMY_TYPES::BOMBER)
			{
				App->particles->AddParticle(App->particles->deadBomber, c1->rect.x, c1->rect.y, COLLIDER_NONE);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			if (enemies[i]->type == ENEMY_TYPES::WINDOWSNIPERLEFT)
			{
				App->particles->AddParticle(App->particles->deadWindowSniperLeft, c1->rect.x, c1->rect.y, COLLIDER_NONE);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			if (enemies[i]->type == ENEMY_TYPES::BACKSTABBER)
			{
				App->particles->AddParticle(App->particles->deadBackStabber, c1->rect.x, c1->rect.y, COLLIDER_NONE);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			if (enemies[i]->type == ENEMY_TYPES::RIFFLEMEN) {
				
					App->particles->AddParticle(App->particles->deadRiffleMen, c1->rect.x, c1->rect.y, COLLIDER_NONE);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
			}
		}
		if (c2->type == COLLIDER_WALL && enemies[i] != nullptr && c1->CheckCollision(c2->rect) == true && enemies[i]->GetCollider() == c1)
		{
			if (c1->rect.y<c2->rect.y + c2->rect.h && c1->rect.y + 3>c2->rect.y + c2->rect.h) {

				enemies[i]->position.y = enemies[i]->position.y + 1;
			}



			else if (c1->rect.y + c1->rect.h > c2->rect.y && c1->rect.y + c1->rect.h - 3< c2->rect.y)

			{
				enemies[i]->position.y = enemies[i]->position.y - 1;

			}


			else if (c1->rect.x + c1->rect.w > c2->rect.x && c1->rect.x + c1->rect.w - 3 < c2->rect.x)
			{
				enemies[i]->position.x = enemies[i]->position.x - 1;

			}
			else if (c1->rect.x < c2->rect.x + c2->rect.w && c1->rect.x + 3 > c2->rect.x + c2->rect.w)
			{
				enemies[i]->position.x = enemies[i]->position.x + 1;

			}

		}
	}
}