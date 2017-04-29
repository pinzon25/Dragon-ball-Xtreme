#include "Application.h"
#include "Enemy_GunMenLeft.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

#define PI 3.14159265
#define ENEMY_SHOOTING_SPEED 3000
#define ENEMY_SHOT_SPEED 3.0f

Enemy_GunMenLeft::Enemy_GunMenLeft(int x, int y) :Enemy(x, y) {

	horizontal.PushBack({ 217,12,17,18 });
	horizontal.PushBack({ 17,52,17,27 });
	horizontal.PushBack({ 56,51,19,27 });
	horizontal.speed = 0.1f;

	path.PushBack({ 0.5,0.f }, 100, &horizontal);
	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_GunMenLeft::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}

void Enemy_GunMenLeft::Shoot() {
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