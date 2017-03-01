/* Include header files here. */
/* Application. */
#include "C_Level.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Level::C_Level() :
	window_(nullptr),
	world_(nullptr),
	level_number_(1)
{}

/*

	Overview
	========
	This method will initialise specific attribute values.

	Params
	======
	sf::RenderWindow* window	-	Provides access to the main render window in the application class.

*/
void C_Level::Init(C_World* world, C_Camera* camera, sf::RenderWindow* window)
{
	/* Initialising local attributes. */
	window_ = window;
	camera_ = camera;
	world_ = world;
	level_generator_.Init(window, world, camera_, level_number_, C_LevelGenerator::Type::forest);
}

/*

	Overview
	========
	Here we will clean up any pointer attributes in this class.

*/
void C_Level::CleanUp()
{
	/* Clean up pointer attributes. */
	DELETE(window_);
}

/*

	Overview
	========
	This method will draw level elements.

*/
void C_Level::Render()
{
	for (size_t i = 0; i < level_generator_.objects_.size(); i++)
	{
		window_->draw(*level_generator_.objects_.at(i));
	}
}

void C_Level::ProcessPlayerCollisions(C_Player& player, C_Body& body, int index)
{
	UNUSED(player);
	UNUSED(index);

	/* If the player has collided with an end level trigger. */
	if (body.id() == ObjectID::endLevelTrigger)
	{
		C_Debug::PrintToConsole("Should end the level...");

		if (level_number_ < 2)
		{
			level_number_++;
		}
		else
		{
			level_number_ = 1;
		}

		/* Process... */
		level_generator_.RestartLevel(level_number_, C_LevelGenerator::Type::desert);
	}
	else if (body.id() == ObjectID::cameraZoomTrigger)
	{
		camera_->zoom(0.75f);
		//level_generator_.objects_.erase(level_generator_.objects_.begin() + index);
	}
}

void C_Level::ProcessLevelObjects(C_GameObject& game_object, float& dt)
{
	switch (game_object.id())
	{
		case(ObjectID::staticObject):
		{
			break;
		}
		case(ObjectID::dynamicObject) :
		{
			break;
		}
		case(ObjectID::cameraZoomTrigger) :
		{
			break;
		}
		case(ObjectID::trigger) :
		{
			break;
		}
		case(ObjectID::endLevelTrigger) :
		{
			break;
		}
		case(ObjectID::ui) :
		{
			break;
		}
		case(ObjectID::playerOne) :
		{
			C_Player* player = static_cast<C_Player*>(&game_object);
			player->Update(dt);
			
			/* Move the background sprite with the player. */
			level_generator_.background_sprite()->setPosition(sf::Vector2f(player->getPosition().x + -(camera_->viewport().width * 0.5f), player->getPosition().y + -(camera_->viewport().height * 0.5f)));

			for (size_t i = 0; i < player->contact().size(); i++)
			{
				ProcessPlayerCollisions(*player, *player->contact()[i], i);
			}

			break;
		}
		case(ObjectID::character) :
		{
			C_Character* character = static_cast<C_Character*>(&game_object);
			character->Update(dt);

			break;
		}
		case(ObjectID::enemy) :
		{
			break;
		}
		default:
		{
			break;
		}
	};

	game_object.Update(dt);
}

/*

	Overview
	========
	This method will update every frame.

	Params
	======
	float& dt	-	Delta time used to determine how much time passed since
					the last frame update.

*/
void C_Level::Update(float& dt)
{	
	/* Update attributes. */
	for (size_t i = 0; i < level_generator_.objects_.size(); i++)
	{
		ProcessLevelObjects(*level_generator_.objects_.at(i), dt);
	}
}