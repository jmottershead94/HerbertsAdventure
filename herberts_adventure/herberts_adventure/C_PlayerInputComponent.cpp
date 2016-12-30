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
void C_PlayerInputComponent::Update(C_GameObject& game_object, float& dt)
{
	/* If the user presses up. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (game_object.rigidbody()->body()->on_the_ground() || game_object.rigidbody()->body()->has_collided())
		{
			game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(0.0f, -game_object.movement_speed() * 20.0f), dt);
			game_object.rigidbody()->body()->ResetCollisionProperties();
		}
	}

	/* If the user presses left. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (game_object.rigidbody()->body()->has_collided())
		{
			game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(-game_object.movement_speed(), -game_object.movement_speed()), dt);
		}
		else
		{
			game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(-game_object.movement_speed(), 0.0f), dt);
		}
	}
	/* If the user presses right. */
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (game_object.rigidbody()->body()->has_collided())
		{
			game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(game_object.movement_speed(), -game_object.movement_speed()), dt);
		}
		else
		{
			game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(game_object.movement_speed(), 0.0f), dt);
		}
	}
}