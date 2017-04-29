#ifndef _ENEMY_WINDOWSNIPERRIGHT_H_
#define _ENEMY_WINDOWSNIPERRIGHT_H_

#include "Enemy.h"
#include "Path.h"

class Enemy_WindowSniperRight : public Enemy
{
private:
	Animation move;
	iPoint speed;
	uint lastTime = 0;
	uint TimeUp = 0;
	float h;
public:

	Enemy_WindowSniperRight(int x, int y);
	void Move();
	void Shoot();
};


#endif