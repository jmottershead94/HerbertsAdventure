/*

	State Splash Class
	==================

	Created:	15th December 2016
	Filter:		State Machine
	Class Name:	C_StateSplash
	Base Class:	C_State
	Author:		Jason Mottershead

	Purpose:	This state will take care of handling splash screen specific functionality
				and rendering.

				This class will initialise all of the pointers that the other inheriting 
				states will use. And will also display some graphics to represent the 
				developer.

*/

/* Header guard. */
#ifndef _C_STATESPLASH_H_
#define _C_STATESPLASH_H_

/* Include header files here. */
/* Application. */
#include "C_State.h"
#include "C_StateTitle.h"

/* State splash IS A state, therfore inherits from it. */
class C_StateSplash : public C_State
{
	public:
		/* Methods. */
		C_StateSplash(sf::RenderWindow* window, sf::Font* font, C_World* world);
		~C_StateSplash();
		bool LoadResources();
		C_State* HandleTransitions();
		void OnEnter();
		void OnExit();
		void Render();
		void Update(float& dt);

	private:
		/* Attributes. */
		C_Timer timer_;					/* Used to provide a timed delay on the splash screen. */
		sf::Sprite sprite_;				/* Used to store the splash screen sprite. */
		sf::SoundBuffer sfx_buffer_;	/* Used to setup the sound. */
		sf::Sound sfx_;					/* Used to play the sound. */
};

#endif