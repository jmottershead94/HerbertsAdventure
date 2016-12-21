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
		void Update(C_GameObject& game_object);

		/* Getters / Setters. */
		inline const float& mass() { return (mass_); }

		inline void ApplyForce(const sf::Vector2f acceleration) { position_ += (mass_ * acceleration); }

	private:
		/* Attributes. */
		int id_ = 0;
		sf::Vector2f position_;		/* Stores the position of the collider */
		float rotation_;			/* Stores the rotation of the collider. */
		sf::FloatRect collider_;	/* Stores the bounds of the collider. */
		float mass_;				/* How much the object weighs. */
		bool is_kinematic_;			/* If this body is kinematic or not. */
		float density_;				/* The density for the body. */
		float friction_;			/* How much friction the body has. */
		float restitution_;			/* How much this body will bounce. */
};

#endif