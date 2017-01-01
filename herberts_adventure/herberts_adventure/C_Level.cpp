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
	level_generator_.Init(window, world, camera_, level_number_);
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

void C_Level::ProcessLevelObjects(C_GameObject& game_object, float& dt)
{
	ObjectID id = game_object.id();

	switch (id)
	{
		case(ObjectID::staticObject):
		{
			game_object.Update(dt);
			break;
		}
		case(ObjectID::dynamicObject) :
		{
			game_object.Update(dt);
			break;
		}
		case(ObjectID::trigger) :
		{
			game_object.Update(dt);
			break;
		}
		case(ObjectID::ui) :
		{
			game_object.Update(dt);

			break;
		}
		case(ObjectID::playerOne) :
		{
			C_Player* player = static_cast<C_Player*>(&game_object);
			player->Update(dt);

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
			game_object.Update(dt);

			break;
		}
		default:
		{
			break;
		}
	}

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