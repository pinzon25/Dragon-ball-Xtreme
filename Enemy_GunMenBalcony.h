
#ifndef __ENEMY_GUNMENBALCONY_H__
#define __ENEMY_GUNMENBALCONY_H__

#include "Enemy.h"
#include "path.h"

class Enemy_GunMenBalcony : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	Animation move;
	Animation stay;
	iPoint speed;
	uint lastTime = 0;
	uint TimeUp = 0;
	float h;

public:

	Enemy_GunMenBalcony(int x, int y);
	void Move();
	void Shoot();
};


#endif