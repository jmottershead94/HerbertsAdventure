/*

	Collision 2D Class
	==================

	Created:	19th December 2016
	Filter:		Physics
	Class Name:	C_Collision2D
	Base Class: N/A
	Author:		Jason Mottershead

	Purpose:	This class will provide a way to check for collisions between 
				two game objects.

*/

/* Header guard. */
#ifndef	_C_COLLISION2D_H_
#define _C_COLLISION2D_H_

/* Include header files here. */
/* Application. */
#include "C_Body.h"

class C_Body;

/* Collision 2D is just a standard class. */
class C_Collision2D
{
	public:
		/* Attributes. */
		enum CollidedSide
		{
			none,
			left,
			top,
			right,
			bottom
		};

		/* Methods. */
		C_Collision2D();
		~C_Collision2D();
		CollidedSide IsColliding(C_Body& game_object, C_Body& other_game_object);

		/* Getters. */
		/* This will allow us to check if two game objects are colliding. */
		//inline const bool is_colliding(C_GameObject& game_object, C_GameObject& other_game_object) { return (game_object.getGlobalBounds().intersects(other_game_object.getGlobalBounds())); }
};

#endif