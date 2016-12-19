/* Include header files here. */
/* Application. */
#include "C_GameObject.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_GameObject::C_GameObject()
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_GameObject::~C_GameObject()
{}

/*

	Overview
	========
	This method will update every frame.

	Params
	======
	float& dt	-	Delta time used to determine how much time passed since
					the last frame update.

*/
void C_GameObject::Update(float& dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);
}