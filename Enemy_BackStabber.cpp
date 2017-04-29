#include "Application.h"
#include "Enemy_BackStabber.h"
#include "ModuleCollision.h"

Enemy_BackStabber::Enemy_BackStabber(int x, int y) :Enemy(x, y) {

	horizontal.PushBack({ 410,167,24,28 });//horizontal
	diagonaldown.PushBack({ 371, 170, 21, 27 });//down
	up.PushBack({ 449, 169, 23, 26 });//up
	stay.PushBack({ 335, 172, 22, 26 });//stay
	horizontal.speed = 0.f;
	diagonaldown.speed = 0.f;
	up.speed = 0.f;
	stay.speed = 0.f;

	path.PushBack({ -1.0f,0.0f }, 75, &horizontal);
	path.PushBack({ -1.0f,1.0f }, 50, &diagonaldown);
	path.PushBack({ 0.f,0.f }, 50, &stay);
	path.PushBack({ -1.0f,-1.0f }, 50, &up);



	collider = App->collision->AddCollider({ 0,0,24,24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

}

void Enemy_BackStabber::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}