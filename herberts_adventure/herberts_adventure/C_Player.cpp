/* Include header files here. */
/* Application. */
#include "C_Player.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Player::C_Player()
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
void C_Player::Init(const std::string filename, const sf::Vector2f position, const float rotation, const sf::Vector2f scale)
{
	/* Handles character initialisation. */
	C_Character::Init(filename, position, rotation, scale);
}

/*

	Overview
	========
	This method will provide user controls for the player character.

	Params
	======
	float& dt	-	Delta time used to determine how much time passed since
					the last frame update.

*/
void C_Player::Controls(float& dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);

	/* Resetting the velocity. */
	set_velocity(sf::Vector2f(0.0f, 0.0f));

	/* If the user presses up. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		/* Move the player up. */
		add_velocity(sf::Vector2f(0.0f, -movement_speed()));
	}

	/* If the user presses left. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		/* Move the player left. */
		add_velocity(sf::Vector2f(-movement_speed(), 0.0f));
	}

	/* If the user presses down. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		/* Move the player down. */
		add_velocity(sf::Vector2f(0.0f, movement_speed()));
	}

	/* If the user presses right. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		/* Move the player right. */
		add_velocity(sf::Vector2f(movement_speed(), 0.0f));
	}

	/* Move the player character. */
	move(velocity());
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
	input_.Update(*this);
}