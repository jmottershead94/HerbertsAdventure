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

	float& dt					-	Delta time used to determine how much time passed since
									the last frame update.
*/
void C_PlayerInputComponent::Update(C_GameObject& game_object, float& dt)
{
	/* If the user presses up. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		/* If the rigidbody is on the ground OR if the rigidbody has collided with something. */
		if (game_object.rigidbody()->body()->on_the_ground() || game_object.rigidbody()->body()->has_collided())
		{
			/* If the rigidbody can jump. */
			if (game_object.rigidbody()->body()->can_jump())
			{
				/* Make the rigidbody jump upward. */
				game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(0.0f, -game_object.movement_speed()), dt);
				game_object.rigidbody()->body()->set_jump_flag(false);
			}
		}
	}

	/* If the user presses left. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		/* Move the rigidbody to the left. */
		game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(-game_object.movement_speed(), 0.0f), dt);

		///* If the rigidbody is on the ground OR if the rigidbody has collided with something. */
		//if (game_object.rigidbody()->body()->on_the_ground() || game_object.rigidbody()->body()->has_collided())
		//{
		//	/* Move the rigidbody to the left and act against gravity. */
		//	game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(-game_object.movement_speed(), -game_object.movement_speed() * 0.0f), dt);
		//}
		///* Otherwise, if the rigidbody is not on the ground. */
		//else if(!game_object.rigidbody()->body()->on_the_ground())
		//{
		//	/* Move the rigidbody to the left. */
		//	game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(-game_object.movement_speed(), 0.0f), dt);
		//}
	}
	/* If the user presses right. */
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		/* Move the rigidbody to the right. */
		game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(game_object.movement_speed(), 0.0f), dt);

		///* If the rigidbody is on the ground OR if the rigidbody has collided with something. */
		//if (game_object.rigidbody()->body()->on_the_ground() || game_object.rigidbody()->body()->has_collided())
		//{
		//	/* Move the rigidbody to the right and act against gravity. */
		//	game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(game_object.movement_speed(), -game_object.movement_speed() * 0.0f), dt);
		//}
		///* Otherwise, if the rigidbody is not on the ground. */
		//else if (!game_object.rigidbody()->body()->on_the_ground())
		//{
		//	/* Move the rigidbody to the right. */
		//	game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(game_object.movement_speed(), 0.0f), dt);
		//}
	}
}