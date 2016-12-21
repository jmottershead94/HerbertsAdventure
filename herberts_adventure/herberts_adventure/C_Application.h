/*

	Application Class
	=================

	Created:	15th December 2016
	Filter:		Header/Source Files
	Class Name:	C_Application
	Base Class:	N/A
	Author:		Jason Mottershead

	Purpose:	This class will provide access to the state machine and the
				SFML window used to display the game.

*/

/* Header guard. */
#ifndef _C_APPLICATION_H_
#define _C_APPLICATION_H_

/* Standard. */
#include <iomanip>

/* Application. */
#include "C_StateSplash.h"

/* Application is just a standard class. */
class C_Application
{
	public:
		/* Methods. */
		C_Application();
		~C_Application();
		void Init(const sf::Vector2i screen_resolution);
		void CleanUp();
		void Render();
		void SetUpFPS(float& dt);
		bool Update(float dt);

		/* Getters. */
		/* This will allow access to the display window. */
		inline const sf::RenderWindow& display_window() { return window_; }

	private:
		/* Attributes */
		const unsigned int kFrameRate = 60;		/* Used to determine the framerate of the application. */
		float fps_;								/* Used to display the frame rate. */
		sf::RenderWindow window_;				/* Used to display the application. */
		sf::Event event_;						/* Used to check window events. */
		sf::Vector2i screen_resolution_;		/* Used to store the current resolution. */
		sf::Text fps_counter_;					/* Used to display the FPS. */
		sf::Font font_;							/* The main font to use for the game. */
		C_World* world_;						/* The main box2D world. */
		C_Utilities utilities_;					/* Used to setup the singleton Utilities access for other classes. */
		C_Debug debug_;							/* Used to setup the singleton Debug access for other classes. */
		C_State* current_state_;				/* Used to setup the state machine for the game flow. */

		/* Methods. */
		void HandleStates();
		void Controls();
};

#endif