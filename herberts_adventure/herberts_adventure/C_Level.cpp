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
void C_Level::Init(C_World* world, sf::RenderWindow* window)
{
	/* Initialising local attributes. */
	window_ = window;
	world_ = world;
	level_generator_.Init(window, world, level_number_);

	/*level_generator_.CreatePlayer(ObjectID::playerOne, sf::Vector2f(window_->getSize().x * 0.35f, window_->getSize().y * 0.5f), sf::Vector2f(1.0f, 1.0f));
	level_generator_.CreateCharacter(ObjectID::character, sf::Vector2f(window_->getSize().x * 0.55f, window_->getSize().y * 0.5f), sf::Vector2f(1.0f, 1.0f));
	level_generator_.CreatePlatform(ObjectID::staticObject, sf::Vector2f(window_->getSize().x * 0.0f, window_->getSize().y * 0.85f), sf::Vector2f(17.0f, 1.0f));
	level_generator_.CreatePlatform(ObjectID::staticObject, sf::Vector2f(window_->getSize().x * 0.75f, window_->getSize().y * 0.75f), sf::Vector2f(5.0f, 1.0f));*/
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
		level_generator_.objects_.at(i)->Update(dt);
	}
}