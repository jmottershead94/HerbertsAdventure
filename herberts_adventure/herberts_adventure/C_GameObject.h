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
		void Update(float& dt);
};

#endif