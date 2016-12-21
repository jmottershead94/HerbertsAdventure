#ifndef _C_WORLD_H_
#define _C_WORLD_H_

#include "C_Body.h"
#include <vector>

class C_GameObject;
class C_Body;

class C_World
{
	public:
		/* Methods. */
		C_World();
		~C_World();
		void Init(const sf::Vector2f gravity);
		void CleanUp();
		void ProcessBodies(float& dt);
		void Update(float& dt);
		C_Body* CreateBody(C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness);

	private:
		/* Attributes. */
		sf::Vector2f gravity_;
		std::vector<C_Body*> bodies_;
};

#endif