#include "Application.h"
#include "Enemy_WindowSniperLeft.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

#define PI 3.14159265
#define ENEMY_SHOOTING_SPEED 3000
#define ENEMY_SHOT_SPEED 3.0f

Enemy_WindowSniperLeft::Enemy_WindowSniperLeft(int x, int y) :Enemy(x, y) {

	move.PushBack({ 214,619,16,12 });
	move.PushBack({ 252,619,18,11 });
	move.PushBack({ 295,616,16,13 });
	move.PushBack({ 252,619,18,11 });
	move.speed = 0.05f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	
}

void Enemy_WindowSniperLeft::Move()
{
	
}

void Enemy_WindowSniperLeft::Shoot()
{
	uint currentTime = SDL_GetTicks();
	float angle;
	speed.x = (App->player->position.x) - position.x;
	speed.y = (App->player->position.y) - (position.y);
	h = sqrt((pow(speed.x, 2) + pow(speed.y, 2)));



	if ((currentTime > (lastTime + ENEMY_SHOOTING_SPEED)) && speed.y<125) {

		App->particles->enemysimplebullet.speed.x = (speed.x / h)*ENEMY_SHOT_SPEED;
		App->particles->enemysimplebullet.speed.y = (speed.y / h)*ENEMY_SHOT_SPEED;


		App->particles->AddParticle(App->particles->enemysimplebullet, position.x + 3, position.y + 3, COLLIDER_ENEMY_SHOT);


		lastTime = currentTime;
	}

}