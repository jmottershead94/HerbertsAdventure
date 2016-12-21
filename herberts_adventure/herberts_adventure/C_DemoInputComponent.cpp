/* Include header files here. */
/* Application. */
#include "C_DemoInputComponent.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_DemoInputComponent::C_DemoInputComponent()
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_DemoInputComponent::~C_DemoInputComponent()
{}

/*

	Overview
	========
	This method will allow the input component to update any game
	object with AI control.

	Params
	======
	C_GameObject& game_object	-	The game object that will be updated with user input.

*/
void C_DemoInputComponent::Update(C_GameObject& game_object, float& dt)
{
	/* Have some AI control the game object... */
	UNUSED(game_object);
	UNUSED(dt);
}