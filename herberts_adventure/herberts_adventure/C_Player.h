/*

	Player Class
	============

	Created:	19th December 2016
	Filter:		Objects
	Class Name:	C_Player
	Base Class: C_Character
	Author:		Jason Mottershead

	Purpose:	The Player class will provide a way for the user to interact with the
				player character in the game.

*/

/* Header guard. */
#ifndef _C_PLAYER_H_
#define _C_PLAYER_H_

/* Include header files here. */
/* Application. */
#include "C_Character.h"

/* Player IS A character, therefore inherits from it. */
class C_Player : public C_Character
{
	public:
		/* Methods. */
		C_Player();
		~C_Player();
		void Init(const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale);
		void Update(float& dt);

	protected:


	private:
		/* Attributes. */
		const float speed_ = 4.0f;

		/* Methods. */
		void Controls(float& dt);
};

#endif