/*

	State Title Class
	=================

	Created:	16th December 2016
	Filter:		State Machine
	Class Name:	C_StateMenu
	Base Class:	C_State
	Author:		Jason Mottershead

	Purpose:	This state will take care of handling main menu specific functionality
				and rendering.

				This class will display the main menu and allow the user to navigate to
				the title screen, game, options or credits scenes.

*/

/* Header guard. */
#ifndef _C_STATEMENU_H_
#define _C_STATEMENU_H_

/* Include header files here. */
/* Application. */
#include "C_State.h"
#include "C_StateTitle.h"
#include "C_StateGame.h"
#include "C_StateOptions.h"
#include "C_StateCredits.h"

/* State menu IS A state, therefore inherits from it. */
class C_StateMenu : public C_State
{
public:
	/* Methods. */
	C_StateMenu(const C_State& current_state);
	~C_StateMenu();
	std::unique_ptr<C_State> HandleTransitions();
	void OnEnter();
	void OnExit();
	void Render();
	void Update(float& dt);

private:
	/* Attributes. */
	C_Button button_play_, button_options_, button_credits_, button_quit_;	/* The buttons used for this state. */
	C_Sprite spr_A_, spr_B_, spr_X_, spr_Y_;
};

#endif