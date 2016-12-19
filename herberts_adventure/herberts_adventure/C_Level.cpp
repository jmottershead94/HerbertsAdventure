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
	/* Initialising local attributes. */
	window_ = window;
	test_.Init(new C_PlayerInputComponent(), "SPR_button.png", sf::Vector2f(window_->getSize().x * 0.25f, window_->getSize().y * 0.5f), 0.0f, sf::Vector2f(1.0f, 1.0f));
	collider_test_.Init("SPR_button.png", sf::Vector2f(window_->getSize().x * 0.75f, window_->getSize().y * 0.5f), 0.0f, sf::Vector2f(1.0f, 1.0f));
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
	/* Draw elements. */
	window_->draw(test_);
	window_->draw(collider_test_);
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
	test_.Update(dt);
	collider_test_.Update(dt);

	/* Testing out collision checks. */
	if (collider_.is_colliding(test_, collider_test_))
	{
		/* Testing out collision response. */
		collider_test_.move(sf::Vector2f(collider_test_.getGlobalBounds().width, 0.0f));
		collider_test_.rotate(90.0f);
	}
}