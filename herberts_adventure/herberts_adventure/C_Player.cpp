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

	const float rotation		-	This will set the rotation of the game object.

	const sf::Vector2 scale		-	This will set the scale of the game object.

*/
void C_Player::Init(const ObjectID id, C_World* world, C_Camera* camera, const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale)
{
	/* Handles character initialisation. */
	C_Character::Init(id, world, new C_PlayerInputComponent(), filename, position, rotation, scale);

	camera_ = camera;
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

	/* Update the camera with the player position. */
	camera_->Update(getPosition(), dt);
}