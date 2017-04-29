
#ifndef __ENEMY_GUNMEN_H__
#define __ENEMY_GUNMEN_H__

#include "Enemy.h"
#include "path.h"

class Enemy_GunMen : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	iPoint speed;
	Animation right;
	Animation downright;
	Animation downleft;
	Animation upright;
	Animation upleft;
	Animation left;
	Animation down;
	uint lastTime = 0;
	uint TimeUp = 0;
	int pathdelay = 0;
	bool gate[4] = { false,false,false,false };
	bool gateright = false;
	bool gateleft = false;
	int repetitions = 0;
	float h;
	uint reseTime;
	uint lastTime2 = 0;

public:

	Enemy_GunMen(int x, int y);
	void Move();
	void Shoot();
};


#endif

