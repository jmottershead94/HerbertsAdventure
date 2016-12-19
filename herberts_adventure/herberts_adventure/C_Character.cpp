/* Include header files here. */
/* Application. */
#include "C_Character.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Character::C_Character()
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_Character::~C_Character()
{}

/*

	Overview
	========
	This method will initialise specific attribute values.

	Params
	======
	const std::string filename	-	This will allow the application to specify the texture filename
	for the game object.

	const sf::Vector2f position	-	This will set the position of the game object.

*/
void C_Character::Init(const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale)
{
	/* Handles base game object initialisation. */
	C_GameObject::Init(filename, position, rotation, scale);
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
void C_Character::Update(float & dt)
{
	/* Handles base game object updates. */
	C_GameObject::Update(dt);
}