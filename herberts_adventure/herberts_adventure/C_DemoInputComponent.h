/*

	Demo Input Component Class
	==========================

	Created:	19th December 2016
	Filter:		Components
	Class Name:	C_DemoInputComponent
	Base Class: C_InputComponent
	Author:		Jason Mottershead

	Purpose:	To setup automatic input for a game object.

*/

/* Header guard. */
#ifndef  _C_DEMOINPUTCOMPONENT_H_
#define  _C_DEMOINPUTCOMPONENT_H_

/* Include header files here. */
/* Application. */
#include "C_InputComponent.h"

/* Demo input component IS AN input component, therfore inherits from it. */
class C_DemoInputComponent : public C_InputComponent
{
public:
	/* Methods. */
	C_DemoInputComponent();
	~C_DemoInputComponent();
	virtual void Update(C_GameObject& game_object);
};

#endif