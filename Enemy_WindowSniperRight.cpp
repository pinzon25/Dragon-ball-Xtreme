#include "Application.h"
#include "Enemy_WindowSniperRight.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"
#include "ModulePlayer.h"

#define PI 3.14159265
#define ENEMY_SHOOTING_SPEED 3000
#define ENEMY_SHOT_SPEED 3.0f


Enemy_WindowSniperRight::Enemy_WindowSniperRight(int x, int y) :Enemy(x, y) {

	move.PushBack({ 176,553,14,11 });
	move.PushBack({ 216,556,16,9 });
	move.PushBack({ 256,556,14,10 });
	move.PushBack({ 216,556,16,9 });
	move.speed = 0.05f;

	animation = &move;

	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);



}

void Enemy_WindowSniperRight::Move()
{
	
}

void Enemy_WindowSniperRight::Shoot()
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