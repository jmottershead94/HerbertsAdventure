/*

	Level Class
	===========

	Created:	16th December 2016
	Filter:		Levels
	Class Name:	C_Level
	Base Class: N/A
	Author:		Jason Mottershead

	Purpose:	Level will provide a way to display a level for the game state,
				and will also help process any level game object updates.

*/

/* Header guard. */
#ifndef _C_LEVEL_H_
#define _C_LEVEL_H_

/* Include header files here. */
/* Application. */
#include "C_LevelGenerator.h"
#include "C_Camera.h"

/* Level is just a standard class. */
class C_Level
{
	public:
		/* Methods. */
		C_Level();
		void Init(C_World* world, C_Camera* camera, sf::RenderWindow* window);
		void CleanUp();
		void Render();
		void ProcessPlayerCollisions(C_Body& game_object);
		void ProcessLevelObjects(C_GameObject& game_object, float& dt);
		void Update(float& dt);

	private:
		/* Attributes. */
		int level_number_ = 1;
		sf::RenderWindow* window_;			/* Points to the main render window in the application class. */
		C_Camera* camera_;
		C_World* world_;					/* Points to the main world in the application class. */
		C_LevelGenerator level_generator_;
};

#endif