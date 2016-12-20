/* Include header files here. */
/* Application. */
#include "C_PlayerInputComponent.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_PlayerInputComponent::C_PlayerInputComponent()
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_PlayerInputComponent::~C_PlayerInputComponent()
{}

/*

	Overview
	========
	This method will allow the input component to update any game
	object with user input.

	Params
	======
	C_GameObject& game_object	-	The game object that will be updated with user input.

*/
void C_PlayerInputComponent::Update(C_GameObject& game_object)
{
	/* If the user presses up. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		/* Move the player up. */
		game_object.rigidbody()->body()->ApplyForce(b2Vec2(0.0f, -game_object.movement_speed()), game_object.rigidbody()->body()->GetWorldCenter(), game_object.rigidbody()->body()->IsAwake());
	}

	/* If the user presses left. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		/* Move the player left. */
		game_object.rigidbody()->body()->ApplyForce(b2Vec2(-game_object.movement_speed(), 0.0f), game_object.rigidbody()->body()->GetWorldCenter(), game_object.rigidbody()->body()->IsAwake());
	}

	/* If the user presses down. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		/* Move the player down. */
		game_object.rigidbody()->body()->ApplyForce(b2Vec2(0.0f, game_object.movement_speed()), game_object.rigidbody()->body()->GetWorldCenter(), game_object.rigidbody()->body()->IsAwake());
	}

	/* If the user presses right. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		/* Move the player right. */
		game_object.rigidbody()->body()->ApplyForce(b2Vec2(game_object.movement_speed(), 0.0f), game_object.rigidbody()->body()->GetWorldCenter(), game_object.rigidbody()->body()->IsAwake());
	}
}