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
	C_InputComponent* input		-	Used to provide input for this game object.

	const std::string filename	-	This will allow the application to specify the texture filename
									for the game object.

	const sf::Vector2f position	-	This will set the position of the game object.

	const float rotation		-	This will set the rotation of the game object.

	const sf::Vector2 scale		-	This will set the scale of the game object.

*/
void C_Character::Init(const ObjectID id, C_World* world, C_InputComponent* input, const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale)
{
	C_PhysicsBody* physics_body = new C_PhysicsBody();
	//C_NullPhysicsComponent* physics_body = new C_NullPhysicsComponent();

	/* Handles base game object initialisation. */
	C_GameObject::Init(id, world, physics_body, input, filename, position, rotation, scale);
	physics_body->Init(id, *this, 1.0f, false, 1.0f, 0.3f, 0.0f);
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