#ifndef __ENEMY_BACKSTABBER_H__
#define __ENEMY_BACKSTABBER_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BackStabber : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	Animation move;
	Animation stay;
	Animation horizontal;
	Animation diagonaldown;
	Animation up;

public:

	Enemy_BackStabber(int x, int y);
	void Move();
};


#endif

