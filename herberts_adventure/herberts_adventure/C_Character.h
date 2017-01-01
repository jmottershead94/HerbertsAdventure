/*

	Character Class
	================

	Created:	19th December 2016
	Filter:		Objects
	Class Name:	C_Character
	Base Class: C_GameObject
	Author:		Jason Mottershead

	Purpose:	Character will provide a way to implement characters into the game
				with standard game object features.

*/

/* Header guard. */
#ifndef _C_CHARACTER_H_
#define _C_CHARACTER_H_

/* Include header files here. */
/* Application. */
#include "C_GameObject.h"
#include "C_PhysicsBody.h"
#include "C_NullPhysicsComponent.h"
#include "C_DemoInputComponent.h"

/* Character IS A game object, therefore inherits from it. */
class C_Character : public C_GameObject
{
	public:
		/* Methods. */
		C_Character();
		~C_Character();
		void Init(const ObjectID id, C_World* world, C_InputComponent* input, const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale);
		void Update(float& dt);

	protected:


	private:
		
};

#endif