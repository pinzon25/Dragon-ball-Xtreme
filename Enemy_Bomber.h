#ifndef __ENEMY_BOMBER_H__
#define __ENEMY_BOMBER_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Bomber : public Enemy
{
private:

	Path path;
	iPoint original_pos;
	Animation move;
	Animation stay;
public:

	Enemy_Bomber(int x, int y);
	void Move();
};


#endif


