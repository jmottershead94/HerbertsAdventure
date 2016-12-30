/*

	Game Object Class
	=================

	Created:	16th December 2016
	Filter:		Objects
	Class Name:	C_GameObject
	Base Class:	sf::Sprite
	Author:		Jason Mottershead

	Purpose:	Game object will be responsible for handling all base object functionality
				for the game and provide access to useful and common attributes for each
				inheriting object.

*/

/* Header guard. */
#ifndef _C_GAMEOBJECT_H_
#define _C_GAMEOBJECT_H_

/* Include header files here. */
/* Application. */
#include "C_Utilities.h"
#include "C_InputComponent.h"
#include "C_Rigidbody2DComponent.h"

/* Forward declaration. */
class C_InputComponent;
class C_Rigidbody2DComponent;
class C_Body;
class C_World;

/* Game object IS A sprite, therefore inherits from it. */
class C_GameObject : public sf::Sprite
{
	public:
		/* Methods. */
		C_GameObject();
		~C_GameObject();
		void Init(const int id, C_World* world, C_Rigidbody2DComponent* rigidbody, C_InputComponent* input, const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale);
		void Update(float& dt);

		/* Getters / Setters. */
		/* This will allow us to get the value of the object movement speed. */
		inline const float& movement_speed() { return (speed_); }

		inline const int& id() { return id_; }

		/* This will allow us to get the current value of the object velocity. */
		inline const sf::Vector2f& velocity() { return (velocity_); }

		/* This will allow us to get the current Box2D world. */
		inline C_World* world() { return world_; }

		/* This will allow us to access the object's rigidbody. */
		inline C_Rigidbody2DComponent* rigidbody() { return rigidbody_; }
		
		/* This will allow us to access the object's input component. */
		inline const C_InputComponent* input_component() { return input_; }

		/* This will allow us to set the value of the velocity. */
		inline void set_velocity(const sf::Vector2f value) { velocity_ = value; }

		/* This will allow us to add onto the value of the current velocity value. */
		inline void add_velocity(const sf::Vector2f value) { velocity_ += value; }

	private:
		/* Attributes. */
		const float speed_ = 10.0f;			/* How fast game objects can move. */
		int id_ = 0;
		sf::Vector2f velocity_;					/* How fast the game object is moving. */
		C_World* world_;						/* Used to access the Box2D world. */
		C_Rigidbody2DComponent* rigidbody_;		/* . */
		C_InputComponent* input_;				/* Used to access the input component. */
};

#endif