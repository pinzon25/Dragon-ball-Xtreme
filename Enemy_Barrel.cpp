#include "Application.h"
#include "Enemy_Barrel.h"
#include "ModuleCollision.h"

Enemy_Barrel::Enemy_Barrel(int x, int y) :Enemy(x, y) {

	move.PushBack({ 369,16,18,18 });

	collider = App->collision->AddCollider({ 0,0,18,18 }, COLLIDER_TYPE::COLLIDER_BARREL, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	life = 5;

}

void Enemy_Barrel::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_PLAYER_SHOT)
		life--;
}