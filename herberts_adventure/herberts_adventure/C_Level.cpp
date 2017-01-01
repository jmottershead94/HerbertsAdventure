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
void C_Level::Init(C_World* world, sf::RenderWindow* window)
{
	/* Initialising local attributes. */
	window_ = window;
	world_ = world;
	test_.Init(ObjectID::playerOne, world_, "SPR_button.png", sf::Vector2f(window_->getSize().x * 0.35f, window_->getSize().y * 0.5f), 0.0f, sf::Vector2f(1.0f, 1.0f));
	collider_test_.Init(ObjectID::character, world_, new C_DemoInputComponent(), "SPR_button.png", sf::Vector2f(window_->getSize().x * 0.55f, window_->getSize().y * 0.5f), 0.0f, sf::Vector2f(1.0f, 1.0f));

	C_PhysicsBody* floor_physics_body = new C_PhysicsBody();
	floor_.Init(ObjectID::staticObject, world_, floor_physics_body, new C_DemoInputComponent(), "SPR_button.png", sf::Vector2f(window_->getSize().x * 0.0f, window_->getSize().y * 0.85f), 0.0f, sf::Vector2f(17.0f, 1.0f));
	floor_physics_body->Init(floor_.id(), floor_, 100.0f, true, 1.0f, 0.3f, 0.3f);

	C_PhysicsBody* platform_physics_body = new C_PhysicsBody();
	platform_.Init(ObjectID::staticObject, world_, platform_physics_body, new C_DemoInputComponent(), "SPR_button.png", sf::Vector2f(window_->getSize().x * 0.75f, window_->getSize().y * 0.75f), 0.0f, sf::Vector2f(5.0f, 1.0f));
	platform_physics_body->Init(platform_.id(), platform_, 100.0f, true, 1.0f, 0.3f, 0.3f);
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
	window_->draw(floor_);
	window_->draw(platform_);
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

	///* Testing out collision checks. */
	//if (collider_.is_colliding(test_, collider_test_))
	//{
	//	/* Testing out collision response. */
	//	collider_test_.move(sf::Vector2f(collider_test_.getGlobalBounds().width, 0.0f));
	//	collider_test_.rotate(90.0f);
	//}
}