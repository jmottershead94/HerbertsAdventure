/*

	State Game Class
	================

	Created:	16th December 2016
	Filter:		State Machine
	Class Name:	C_StateGame
	Base Class:	C_State
	Author:		Jason Mottershead

	Purpose:	This state will take care of handling game specific functionality
				and rendering.

				This class will display the game state and allow the user to navigate to
				the title screen, game, options or credits scenes.

*/

/* Header guard. */
#ifndef _C_STATEGAME_H_
#define _C_STATEGAME_H_

/* Include header files here. */
/* Application. */
#include "C_State.h"
#include "C_StateMenu.h"
#include "C_StateCredits.h"

/* State game IS A state, therefore inherits from it. */
class C_StateGame : public C_State
{
public:
	/* Methods. */
	C_StateGame(const C_State& current_state);
	~C_StateGame();
	std::unique_ptr<C_State> HandleTransitions();
	void OnEnter();
	void OnExit();
	void Render();
	void Update(float& dt);

private:
	/* Attributes. */
	
};

#endif