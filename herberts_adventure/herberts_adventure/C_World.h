#ifndef _C_WORLD_H_
#define _C_WORLD_H_

#include <vector>

#include "C_Collision2D.h"
//#include "C_Body.h"

class C_GameObject;
class C_Body;
class C_Collision2D;

class C_World
{
	public:
		/* Methods. */
		C_World();
		~C_World();
		void Init(const sf::Vector2f gravity);
		void CleanUp();
		void CheckBodyCollisions(C_Body& body, size_t index);
		void BodyCollisionResponse(C_Body& body, float& dt);
		void ProcessBodies(float& dt);
		void Update(float& dt);
		C_Body* CreateBody(const int id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness);

	private:
		/* Attributes. */
		sf::Vector2f gravity_;
		std::vector<C_Body*> bodies_;
		C_Collision2D* collider_manager_;

};

#endif