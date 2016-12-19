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
void C_GameObject::Init(C_InputComponent* input, const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale)
{
	/* Loading a texture. */
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../assets/art/" + filename);

	/* Initialising the game object. */
	setTexture(*texture);
	setPosition(position);
	setRotation(rotation);
	setScale(scale);

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
void C_GameObject::Update(float& dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);

	/* Update the input component. */
	input_->Update(*this);
}