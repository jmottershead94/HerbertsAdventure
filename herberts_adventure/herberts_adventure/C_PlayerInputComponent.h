/*

	Player Input Component Class
	============================

	Created:	19th December 2016
	Filter:		Components
	Class Name:	C_PlayerInputComponent
	Base Class: C_InputComponent
	Author:		Jason Mottershead

	Purpose:	To setup input for the player.

*/

/* Header guard. */
#ifndef  _C_PLAYERINPUTCOMPONENT_H_
#define  _C_PLAYERINPUTCOMPONENT_H_

/* Include header files here. */
/* Application. */
#include "C_InputComponent.h"

/* Player input component IS AN input component, therfore inherits from it. */
class C_PlayerInputComponent : public C_InputComponent
{
	public:
		/* Methods. */
		C_PlayerInputComponent();
		~C_PlayerInputComponent();
		virtual void Update(C_GameObject& game_object, float& dt);
};

#endif