#ifndef __ENEMY_RIFFLEMEN_H__
#define __ENEMY_RIFFLEMEN_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_RiffleMen : public Enemy
{
private:
	
	Path path;
	iPoint original_pos;
	Animation move;
	Animation sides;

public:

	Enemy_RiffleMen(int x, int y);
	void Move();
};


#endif


