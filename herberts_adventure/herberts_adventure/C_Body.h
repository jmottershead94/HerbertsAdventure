#ifndef _C_BODY_H_
#define _C_BODY_H_

#include "C_GameObject.h"

class C_GameObject;

class C_Body
{
	/* Perhaps have the world as a friend class? */
	friend class C_World;

	public:
		/* Methods. */
		C_Body();
		~C_Body();
		void Init(const int id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness);
		void ApplyForce(const sf::Vector2f force, float& dt);
		void ResetCollisionProperties();
		//bool Raycast();
		void Update(C_GameObject& game_object);

		/* Getters / Setters. */
		inline std::vector<C_Body*> colliding_bodies() { return colliding_bodies_; }

		inline std::vector<bool> collision_flags() { return collision_flags_; }

		inline const float& mass() { return (mass_); }

		inline const bool& on_the_ground() { return on_ground_; }

		inline const bool& has_collided() { return collided_; }

		inline sf::Vector2f& velocity() { return velocity_; }

		inline sf::FloatRect& collider() { return collider_; }

		inline void set_on_ground(const bool value) { on_ground_ = value; }

		inline void set_collided(const bool value) { collided_ = value; }

		//inline void ApplyForce(const sf::Vector2f acceleration) { position_ += (mass_ * acceleration); }

	private:
		/* Attributes. */
		std::vector<C_Body*> colliding_bodies_;
		std::vector<bool> collision_flags_;
		int id_ = 0;
		bool on_ground_ = false;
		bool collided_ = false;
		C_Body* colliding_body_;	/* Stores the body that the collider is currently colliding with. */
		sf::Vector2f position_;		/* Stores the position of the collider */
		sf::Vector2f translation_;	
		sf::Vector2f velocity_;
		float rotation_;			/* Stores the rotation of the collider. */
		sf::FloatRect collider_;	/* Stores the bounds of the collider. */
		float mass_;				/* How much the object weighs. */
		float inverse_mass_;		/* The inverse of the mass. */
		bool is_kinematic_;			/* If this body is kinematic or not. */
		float density_;				/* The density for the body. */
		float friction_;			/* How much friction the body has. */
		float restitution_;			/* How much this body will bounce. */
};

#endif