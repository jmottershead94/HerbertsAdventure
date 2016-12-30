/*

	State Credits Class
	===================

	Created:	16th December 2016
	Filter:		State Machine
	Class Name:	C_StateCredits
	Base Class:	C_State
	Author:		Jason Mottershead

	Purpose:	This state will take care of handling game specific functionality
				and rendering.

				This class will display the credits screen and allow the user to 
				navigate to main menu.

*/

/* Header guard. */
#ifndef _C_STATECREDITS_H_
#define _C_STATECREDITS_H_

/* Include header files here. */
/* Application. */
#include "C_State.h"
#include "C_StateMenu.h"

/* State credits IS A state, therefore inherits from it. */
class C_StateCredits : public C_State
{
public:
	/* Methods. */
	C_StateCredits(const C_State& current_state);
	~C_StateCredits();
	C_State* HandleTransitions();
	void OnEnter();
	void OnExit();
	void Render();
	void Update(float& dt);

private:
	/* Attributes. */
	sf::Text splash_sfx_credit_, main_music_credit_, developer_credit_;		/* The text used to display credits for assets used. */
	C_Button button_menu_;													/* The button used to navigate back to the main menu. */
};

#endif