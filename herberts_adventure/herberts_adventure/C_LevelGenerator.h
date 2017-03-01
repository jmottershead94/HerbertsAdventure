/*

	Level Generator Class
	=====================

	Created:	1st January 2016
	Filter:		Levels
	Class Name:	C_LevelGenerator
	Base Class: N/A
	Author:		Jason Mottershead

	Purpose:	Level Generator will provide a way of creating and 
				reading level layouts from text files.

				This class will also provide a factory setup for creating
				different level objects.

*/

/* Header guard. */
#ifndef _C_LEVELGENERATOR_H_
#define _C_LEVELGENERATOR_H_

/* Include header files here. */
/* Standard. */
#include <fstream>
#include <vector>

/* Application. */
#include "C_Utilities.h"
#include "C_UIElement.h"
#include "C_Player.h"

/* Level is just a standard class. */
class C_LevelGenerator
{
	/* Level is a friend class because level should be able to easily access all private level generator attributes/methods. */
	friend class C_Level;

	private:
		/* Attributes. */
		std::ifstream* ifstream_;
		std::vector<C_GameObject*> objects_;
		sf::RenderWindow* window_;
		C_GameObject* bg_;
		C_Camera* camera_;
		std::shared_ptr<C_World> world_;
		enum Type
		{
			forest,
			desert
		};

		/* Methods. */
		C_LevelGenerator();
		~C_LevelGenerator();
		void Init(sf::RenderWindow* window, std::shared_ptr<C_World> world, C_Camera* camera, int& level_number, Type level_type);
		void RestartLevel(int& level_number, Type level_type);
		void IncrementObjectWidth(float& width, int& text_file_width, int& map_x, char& file_char);
		void ReadTextFile();
		C_GameObject* CreateBackground(const std::string filename);
		C_Player* CreatePlayer(const ObjectID id, C_Camera* camera, sf::Vector2f position, sf::Vector2f scale);
		C_Character* CreateCharacter(const ObjectID id, sf::Vector2f position, sf::Vector2f scale);
		C_GameObject* CreateTrigger(const ObjectID id, sf::Vector2f position, sf::Vector2f scale);
		C_GameObject* CreateBox(const ObjectID id, sf::Vector2f position, sf::Vector2f scale);
		C_GameObject* CreateBouncingBox(const ObjectID id, sf::Vector2f position, sf::Vector2f scale);
		C_GameObject* CreateFinishPoint(const ObjectID id, sf::Vector2f position, sf::Vector2f scale);
		C_GameObject* CreatePlatform(const ObjectID id, sf::Vector2f position, sf::Vector2f scale);

		inline C_GameObject* background_sprite() { return bg_; }
};

#endif