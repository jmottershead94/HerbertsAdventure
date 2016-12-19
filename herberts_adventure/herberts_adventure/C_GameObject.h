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

/* Game object IS A sprite, therefore inherits from it. */
class C_GameObject : public sf::Sprite
{
	public:
		/* Methods. */
		C_GameObject();
		~C_GameObject();
		void Init(const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale);
		void Update(float& dt);

		/* Getters / Setters. */
		inline const sf::Vector2f& velocity() { return (velocity_); }

		inline void set_velocity(const sf::Vector2f value) { velocity_ = value; }

		inline void add_velocity(const sf::Vector2f value) { velocity_ += value; }

	private:
		/* Attributes. */
		sf::Vector2f velocity_;	/* How fast the game object is moving. */
};

#endif