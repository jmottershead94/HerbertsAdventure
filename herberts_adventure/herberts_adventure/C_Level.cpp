/* Include header files here. */
/* Application. */
#include "C_Level.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Level::C_Level() :
	window_(nullptr)
{}

/*

	Overview
	========
	This method will initialise specific attribute values.

	Params
	======
	sf::RenderWindow* window	-	Provides access to the main render window in the application class.

*/
void C_Level::Init(sf::RenderWindow* window)
{
	/* Initialising attributes. */
	window_ = window;
	test_.setColor(sf::Color::White);
	test_.setPosition(sf::Vector2f(window_->getSize().x * 0.5f, window_->getSize().y * 0.5f));
}

void C_Level::CleanUp()
{
	/* Clean up pointer attributes. */
	DELETE(window_);
}

void C_Level::Render()
{
	window_->draw(test_);
}

void C_Level::Update(float& dt)
{
	test_.Update(dt);
}