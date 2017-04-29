//#include "Application.h"
//#include "Enemy_PowerUp.h"
//#include "ModuleCollision.h"
//#include "Path.h"
//#include"ModuleInput.h"
//#include "ModulePlayer.h"
//
//Enemy_PowerUp::Enemy_PowerUp(int x, int y) : Enemy(x, y)
//{
//	boots.PushBack({80,10,16,16});
//	boots.PushBack({ 80,34,16,16 });
//	boots.speed = 1.0f;
//	
//
//	animation = &boots;
//
//	position.x = x;
//	position.y = y;
//
//	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_POWERUPS, (Module*)App->enemies);
//
//	
//}
//
//void Enemy_PowerUp::OnCollision(Collider* c1, Collider* c2)
//{
//	if (c2->type == COLLIDER_PLAYER) {
//		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) {
//			App->player->position.y -= 2;
//		}
//		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) {
//			App->player->position.y += 2;
//		}
//		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {
//			App->player->position.y -= 2;
//		}
//		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {
//			App->player->position.y += 2;
//		}
//	}
//
//	
//}
