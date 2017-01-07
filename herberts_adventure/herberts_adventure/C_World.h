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
		void ClearBodies();
		void CheckCollision(C_Body& bodyA, C_Body& bodyB);
		void Update(float& dt);
		C_Body* CreateBody(const ObjectID id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness);

	private:
		/* Attributes. */
		//const float MAX_VELOCITY = 15.0f;
		//const sf::Vector2f MAX_VELOCITY = sf::Vector2f(250.0f, 250.0f);
		sf::Vector2f gravity_;
		std::vector<C_Body*> bodies_;
		C_Collision2D* collider_manager_;

		/* Methods. */
		void CheckBodyCollisions(C_Body& body);
		void ResolveCollision(C_Body& bodyA, C_Body& bodyB, float& dt);
		void BodyCollisionResponse(C_Body& body, float& dt);
		void ProcessBodies(float& dt);

};

#endif