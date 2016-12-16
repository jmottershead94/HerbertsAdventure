/*

	State Title Class
	=================

	Created:	15th December 2016
	Filter:		State Machine
	Class Name:	C_StateTitle
	Base Class:	N/A
	Author:		Jason Mottershead

	Purpose:	This state will take care of handling title screen specific functionality
				and rendering.

				This class will display the title screen and allow the user to navigate to
				the main menu.

*/

/* Header guard. */
#ifndef _C_STATETITLE_H_
#define _C_STATETITLE_H_

/* Include header files here. */
/* Application. */
#include "C_State.h"

/* State title IS A state, therefore inherits from it. */
class C_StateTitle : public C_State
{
	public:
		/* Methods. */
		C_StateTitle(const C_State& current_state);
		~C_StateTitle();
		C_State* HandleTransitions();
		void OnEnter();
		void OnExit();
		void Render();
		void Update(float& dt);

	private:
		/* Attributes. */
		sf::Text message_;
};

#endif