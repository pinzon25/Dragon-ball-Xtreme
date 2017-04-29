#include "Application.h"
#include "Enemy_GunMen.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_timer.h"

#define PI 3.14159265
#define ENEMY_SHOOTING_SPEED 3000
#define ENEMY_SHOT_SPEED 3.0f

Enemy_GunMen::Enemy_GunMen(int x, int y) :Enemy(x, y) {

	down.PushBack({ 214, 51, 20, 28 });
	down.PushBack({ 254, 53, 20, 28 });
	down.PushBack({ 294, 51, 20, 28 });
	down.speed = 0.07f;

	right.PushBack({ 337, 12, 15, 26 });
	right.PushBack({ 18, 53, 15, 25 });
	right.PushBack({ 57, 52, 17, 25 });
	right.speed = 0.07f;

	left.PushBack({ 93, 92, 18, 25 });
	left.PushBack({ 132, 93, 19, 26 });
	left.PushBack({ 171, 92, 22, 25 });
	left.speed = 0.07f;

	upright.PushBack({ 97, 13, 18, 25 });
	upright.PushBack({ 136, 12, 20, 27 });
	upright.PushBack({ 258, 13, 17, 27 });
	upright.PushBack({ 297, 12, 19, 27 });
	upright.speed = 0.07f;

	upleft.PushBack({ 215, 92, 17, 27 });
	upleft.PushBack({ 258, 93, 14, 27 });
	upleft.PushBack({ 298, 92, 14, 27 });
	upleft.speed = 0.07f;

	downright.PushBack({ 94, 52, 19, 27 });
	downright.PushBack({ 135, 53, 17, 26 });
	downright.PushBack({ 176, 52, 16, 26 });
	downright.speed = 0.07f;

	downleft.PushBack({ 331, 52, 21, 26 });
	downleft.PushBack({ 11, 93, 22, 27 });
	downleft.PushBack({ 51, 92, 24, 27 });
	downleft.speed = 0.07f;

	animation = &down;


	collider = App->collision->AddCollider({ 0,0,20,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_GunMen::Move()
{
	float h = sqrt(pow(2, (App->player->position.x - position.x)) + (pow(2, (App->player->position.y - position.y))));
	float angle;
	speed.x = App->player->position.x - position.x;
	speed.y = App->player->position.y - position.y;


	//position = original_pos + path.GetCurrentSpeed();

		if (speed.x != 0) {
			angle = atan2(speed.y, speed.x);

			//LOG("%f", to_degrees(angle));
		}
		else {
			angle = atan2(speed.y, speed.x + 1);
			//LOG("%f", to_degrees(angle));
		}

		if (to_degrees(angle) <= 25 && to_degrees(angle) > -25) {
			animation = &right;
		}

		else if (to_degrees(angle) <= 75 && to_degrees(angle) > 25) {
			animation = &downright;
		}

		else if (to_degrees(angle) <= 105 && to_degrees(angle) > 75) {
			animation = &down;
		}
		else if (to_degrees(angle) <= 155 && to_degrees(angle) > 105) {
			animation = &downleft;
		}
		else if ((to_degrees(angle) <= -155) || (to_degrees(angle) > 155)) {
			animation = &left;
		}
		else if (to_degrees(angle) <= -90 && to_degrees(angle) > -155) {
			animation = &upleft;
		}
		else if (to_degrees(angle) <= -25 && to_degrees(angle) > -90) {
			animation = &upright;
		}






		//*************************************** Movement

		uint Time = SDL_GetTicks();

		if (abs(App->player->position.y - position.y < 300))
			gate[0] = true;

		if (gate[3] == true ) {
			position.x--;
			position.y--;
			if (Time - (reseTime*repetitions) >(TimeUp + pathdelay))
			{
				//pathdelay = 0;
				//TimeUp = Time;
				reseTime = 13000;
				repetitions++;
				for (int i = 0; i < 4; i++) {
					gate[i] = false;
				}
			}


		}
		else if (gate[2] == true ) {//down
			position.y++; //y++
			if (Time - (reseTime*repetitions) >(TimeUp + pathdelay))
			{
				pathdelay += 3000;
				gate[3] = true;
			}
		}
		else if (gate[1] == true) {//upleft
			position.x++;
			position.y--;
			if (Time - (reseTime*repetitions) > (TimeUp + pathdelay)) {
				pathdelay += 3000;
				gate[2] = true;
			}

		}
		else if (gate[0] == true ) {//down

			position.y++; //y++
			pathdelay = 4000;
			if (Time - (reseTime*repetitions) > (TimeUp + pathdelay))
			{
				pathdelay += 3000;
				gate[1] = true;
			}
		}


		if (position.x >= 200 ) {

			position.x--;
		}
		if (position.x <= 5 )
			position.x++;

		
	
}

void Enemy_GunMen::Shoot()
{
	uint currentTime = SDL_GetTicks();
	float angle;
	speed.x = (App->player->position.x) - position.x;
	speed.y = (App->player->position.y) - (position.y);
	h = sqrt((pow(speed.x, 2) + pow(speed.y, 2)));



	if ((currentTime > (lastTime + ENEMY_SHOOTING_SPEED)) && speed.y<125 ) {

		App->particles->enemysimplebullet.speed.x = (speed.x / h)*ENEMY_SHOT_SPEED;
		App->particles->enemysimplebullet.speed.y = (speed.y / h)*ENEMY_SHOT_SPEED;


		App->particles->AddParticle(App->particles->enemysimplebullet, position.x+3, position.y+3, COLLIDER_ENEMY_SHOT);


		lastTime = currentTime;
	}

}
