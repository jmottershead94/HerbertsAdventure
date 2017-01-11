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
	/* If the user presses the jump button. */
	if (C_Input::JumpPressed())
	{
		/* If the rigidbody is on the ground OR if the rigidbody has collided with something. */
		if (game_object.rigidbody()->body()->on_the_ground() /*&& !game_object.rigidbody()->body()->collided_above()*/ || game_object.rigidbody()->body()->has_collided())
		{
			/* If the rigidbody can jump. */
			if (game_object.rigidbody()->body()->can_jump())
			{
				/* Make the rigidbody jump upward. */
				game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(0.0f, -250.0f), dt);
				game_object.rigidbody()->body()->set_jump_flag(false);
			}
		}
	}

	/* If the user presses left. */
	if (C_Input::LeftPressed())
	{
		/*if(!game_object.rigidbody()->body()->collided_left())*/
			game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(-250.0f, 0.0f), dt);
	}
	/* If the user presses right. */
	else if (C_Input::RightPressed())
	{
		/*if(!game_object.rigidbody()->body()->collided_right())*/
			game_object.rigidbody()->body()->ApplyForce(sf::Vector2f(250.0f, 0.0f), dt);
	}
}