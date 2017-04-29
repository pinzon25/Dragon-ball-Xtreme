#ifndef _ENEMY_BARREL_H_
#define _ENEMY_BARREL_H_

#include "Enemy.h"
#include "Path.h"

class Enemy_Barrel : public Enemy
{
private:

	Animation move;
	iPoint original_pos;


public:

	Enemy_Barrel(int x, int y);
	void OnCollision(Collider* c1, Collider* c2);
	int life;
};


#endif
