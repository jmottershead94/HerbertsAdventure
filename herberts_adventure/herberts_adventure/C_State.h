/*

	State Class
	===========

	Created:	15th December 2016
	Filter:		State Machine
	Class Name:	C_State
	Base Class:	N/A
	Author:		Jason Mottershead

	Purpose:	The state class is used to setup the state machine for the UI/game flow
				states,	and will provide access to the attributes from the main application.

				All other UI states will inherit from this base UI state and will have
				to implement any pure virtual methods in order to work.

*/

/* Header guard. */
#ifndef _C_STATE_H_
#define _C_STATE_H_

/* Include header files here. */
/* Application. */
#include "C_Utilities.h"
#include "C_Timer.h"
#include "C_Level.h"
#include "C_Button.h"

/* State is just a standard class. */
class C_State
{
	public:
		/* Methods. */
		/* Virtual. */
		virtual ~C_State() {};

		/* Pure virtual functions that every state MUST have. */
		/* Intended to be overwritten by the more specific states. */
		/* Handling transitions between states (either input or automatic). */
		virtual C_State* HandleTransitions() = 0;

		/* Providing each state with it's own entering sequence. */
		virtual void OnEnter() = 0;

		/* Providing each state with it's own exiting sequence. */
		virtual void OnExit() = 0;

		/* Render to setup the overall rendering process for each state. */
		virtual void Render() = 0;

		/* Not a pure virtual function because when a state cleans up, it should go back here. */
		/* All of the pointers will be erased. */
		virtual void CleanUp();
		virtual void Update(float& dt);

	protected:
		/* Attributes. */
		sf::RenderWindow* window_;		/* Will be used to point to the main game window. */
		sf::Texture* ui_bg_;			/* Used to store the background image for different states. */
		sf::Sprite ui_bg_sprite_;		/* Used to display the background image. */
		sf::Font* font_;				/* Will be used to point to the main font. */
		sf::Text title_text_;			/* Used to allow inheriting states their own title text. */
		C_World* world_;				/* Will be used to point to the main Box2D world. */
		C_Timer input_delay_;			/* Used to delay input slightly between state transitions. */
		C_Level	level_;					/* Used to access the level for the game state (and possibly game over for game play elements). */
};

#endif