/* Include header files here. */
/* Application. */
#include "C_State.h"

/*

	Overview
	========
	Here we will clean up any pointer attributes in this class.

*/
void C_State::CleanUp()
{
	/* Clean up state machine pointer attributes. */
	DELETE(window_);
}

/*

	Overview
	========
	This method will update every frame.

	Params
	======
	float& dt			-	Delta time used to determine how much time passed since
							the last frame update.

*/
void C_State::Update(float& dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);
}