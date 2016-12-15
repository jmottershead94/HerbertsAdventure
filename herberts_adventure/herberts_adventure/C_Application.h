/*

	Level Class
	===========

	Created:	15th December 2016
	Filter:		Header/Source Files
	Class Name:	C_Application
	Base Class:	N/A
	Author:		Jason Mottershead

	Purpose:	This class will provide access to the state machine and the
				SFML window used to display the game.

*/

#ifndef _C_APPLICATION_H_
#define _C_APPLICATION_H_

/* Include header files here. */
/* SFML. */
#include "SFML\Graphics.hpp"

/* Application. */
#include "C_Utilities.h"

class C_Application
{
	public:
		/* Methods. */
		C_Application();
		void Init(const sf::Vector2i screen_resolution);
		void CleanUp();
		void Render();
		bool Update(float dt);

		/* Getters. */
		/* This will allow access to the display window. */
		inline const sf::RenderWindow& display_window() { return window_; }

	private:
		/* Attributes */
		const unsigned int kFrameRate = 60;		/* Used to determine the framerate of the application. */
		sf::RenderWindow window_;				/* Used to display the application. */
		sf::Event event_;						/* Used to check window events. */
		sf::Vector2i screen_resolution_;		/* Used to store the current resolution. */

		/* Methods. */
		void HandleStates();
		void Controls();
};

#endif