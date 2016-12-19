/* Include header files here. */
/* Application. */
#include "C_Player.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Player::C_Player() :
	input_(nullptr)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_Player::~C_Player()
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
void C_Player::Init(C_InputComponent* input, const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale)
{
	/* Handles character initialisation. */
	C_Character::Init(filename, position, rotation, scale);

	/* Initialising local attributes. */
	input_ = input;
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
void C_Player::Update(float & dt)
{
	/* Handles character updates. */
	C_Character::Update(dt);

	/* Update the input component. */
	input_->Update(*this);
}