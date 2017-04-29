#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

#define PI 3.14

Enemy::Enemy(int x, int y) : position(x, y), collider(nullptr)
{}

Enemy::~Enemy()
{
	if(collider != nullptr)
		App->collision->EraseCollider(collider);
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Draw(SDL_Texture* sprites)
{
	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void Enemy::OnCollision(Collider* collider) {

}
void Enemy::Shoot() {

}

float Enemy::to_degrees(float num) {
	num = num*180.0f / PI;
	return num;
}