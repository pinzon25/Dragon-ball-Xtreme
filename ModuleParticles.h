#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 200

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

enum PARTICLE_TYPE
{
	PARTICLE_NONE = 0,
	PARTICLE_PLAYER_SHOT,
	PARTICLE_ENEMY_SHOT,
	PARTICLE_BOMB,
	PARTICLE_BOMBEXP,

};


struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture* graphics = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];

public:

	Particle bulletu;
	Particle bulletl;
	Particle bulletr;
	Particle explosion;
	Particle deadGunMen;
	Particle enemysimplebullet;
	Particle enemysimplebulletdead;
	Particle deadWindowSniperRight;
	Particle deadBomber;
	Particle deadWindowSniperLeft;
	Particle deadBackStabber;
	Particle deadBarrel;
	Particle playerdead;
	Particle deadRiffleMen;
	Particle playerhit;
	
};

#endif // __MODULEPARTICLES_H__