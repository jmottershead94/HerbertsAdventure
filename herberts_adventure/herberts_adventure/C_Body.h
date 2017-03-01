#ifndef _C_BODY_H_
#define _C_BODY_H_

#include "C_GameObject.h"

class C_GameObject;
class C_Collision2D;

class C_Body
{
	/* Perhaps have the world as a friend class? */
	friend class C_World;

	public:
		/* Methods. */
		C_Body();
		~C_Body();
		void Init(const ObjectID id, C_GameObject& game_object, const float mass, const bool is_kinematic, const float density, const float friction, const float bounciness);
		void ApplyForce(const sf::Vector2f force, float& dt);
		void ResetCollisionProperties();
		void Update(C_GameObject& game_object, float& dt);

		/* Getters / Setters. */
		inline std::vector<C_Body*> colliding_bodies() { return colliding_bodies_; }

		inline std::vector<bool> collision_flags() { return collision_flags_; }

		inline std::vector<int> collisions() { return collisions_; }

		inline ObjectID id() { return id_; }

		inline const float& mass() { return (mass_); }

		inline const bool& on_the_ground() { return on_ground_; }

		inline const bool& can_jump() { return can_jump_; }

		inline const bool& has_collided() { return collided_; }

		inline const bool& collided_left() { return colliding_left_; }

		inline const bool& collided_right() { return colliding_right_; }

		inline const bool& collided_above() { return colliding_top_; }

		inline const bool& collided_below() { return colliding_bottom_; }

		inline const bool& being_destroyed() { return destroy_; }

		inline sf::Vector2f& velocity() { return velocity_; }

		inline sf::FloatRect& collider() { return collider_; }

		inline void should_destroy(const bool value) { destroy_ = value; }

		inline void set_on_ground(const bool value) { on_ground_ = value; }

		inline void set_jump_flag(const bool value) { can_jump_ = value; }

		inline void set_collided(const bool value) { collided_ = value; }

	private:
		/* Attributes. */
		std::vector<C_Body*> colliding_bodies_;
		std::vector<int> collisions_;
		std::vector<bool> collision_flags_;
		ObjectID id_ = ObjectID::staticObject;
		bool colliding_left_ = false, colliding_top_ = false, colliding_right_ = false, colliding_bottom_ = false;
		bool on_ground_ = false;
		bool can_jump_ = false;
		bool collided_ = false;
		bool is_trigger_ = false;
		bool destroy_ = false;
		C_Body* colliding_body_;	/* Stores the body that the collider is currently colliding with. */
		sf::Vector2f position_;		/* Stores the position of the collider */
		sf::Vector2f translation_;	
		sf::Vector2f velocity_;
		const sf::Vector2f MAX_VELOCITY = sf::Vector2f(250.0f, 750.0f);
		float rotation_;			/* Stores the rotation of the collider. */
		sf::FloatRect collider_;	/* Stores the bounds of the collider. */
		float mass_;				/* How much the object weighs. */
		float inverse_mass_;		/* The inverse of the mass. */
		bool is_kinematic_;			/* If this body is kinematic or not. */
		float density_;				/* The density for the body. */
		float friction_;			/* How much friction the body has. */
		float restitution_;			/* How much this body will bounce. */

		/* Methods. */
		void CheckVelocityValue();
};

#endif