#include "Application.h"
#include "Enemy_GunMenBalcony.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

#define PI 3.14159265
#define ENEMY_SHOOTING_SPEED 3000
#define ENEMY_SHOT_SPEED 3.0f

Enemy_GunMenBalcony::Enemy_GunMenBalcony(int x, int y) :Enemy(x, y) {

	move.PushBack({ 214, 51, 20, 28 });
	move.PushBack({ 254, 53, 20, 28 });
	move.PushBack({ 294, 51, 20, 28 });
	move.speed = 0.07f;
	/*stay.PushBack({})*/
	stay.PushBack({ 214, 51, 20, 28 });
	stay.PushBack({ 254, 53, 20, 28 });
	stay.PushBack({ 294, 51, 20, 28 });
	stay.speed = 0.03f;

	path.PushBack({ 0.f,0.5f }, 75, &move);
	path.PushBack({ 0.f,0.f }, 400, &stay);



	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_GunMenBalcony::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}

void Enemy_GunMenBalcony::Shoot() {
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