/*

	Input Component Class
	=====================

	Created:	19th December 2016
	Filter:		Components
	Class Name:	C_InputComponent
	Base Class: N/A
	Author:		Jason Mottershead

	Purpose:	To setup input for a game object. This will be the base class
				for all input components.

*/

/* Header guard. */
#ifndef  _C_INPUTCOMPONENT_H_
#define  _C_INPUTCOMPONENT_H_

/* Include header files here. */
/* Application. */
#include "C_GameObject.h"

/* Forward declaration. */
class C_GameObject;

/* Input component is just a standard class. */
class C_InputComponent
{
	public:
		/* Methods. */
		virtual ~C_InputComponent();
		virtual void Update(C_GameObject& game_object) = 0;
};

#endif