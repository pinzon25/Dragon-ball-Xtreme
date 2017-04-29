#ifndef __ENEMY_GUNMENRIGHT_H__
#define __ENEMY_GUNMENRIGHT_H__

#include "Enemy.h"
#include "path.h"

class Enemy_GunMenRight : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	Animation horizontal;
	iPoint speed;
	uint lastTime = 0;
	uint TimeUp = 0;
	float h;
public:

	Enemy_GunMenRight(int x, int y);
	void Move();
	void Shoot();
};


#endif

