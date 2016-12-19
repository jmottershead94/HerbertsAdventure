#include "C_InputComponent.h"

C_InputComponent::C_InputComponent()
{}

C_InputComponent::~C_InputComponent()
{}

void C_InputComponent::Update(C_GameObject & game_object)
{
	/* Resetting the velocity. */
	game_object.set_velocity(sf::Vector2f(0.0f, 0.0f));

	/* If the user presses up. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		/* Move the player up. */
		game_object.add_velocity(sf::Vector2f(0.0f, -game_object.movement_speed()));
	}

	/* If the user presses left. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		/* Move the player left. */
		game_object.add_velocity(sf::Vector2f(-game_object.movement_speed(), 0.0f));
	}

	/* If the user presses down. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		/* Move the player down. */
		game_object.add_velocity(sf::Vector2f(0.0f, game_object.movement_speed()));
	}

	/* If the user presses right. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		/* Move the player right. */
		game_object.add_velocity(sf::Vector2f(game_object.movement_speed(), 0.0f));
	}

	/* Move the player character. */
	game_object.move(game_object.velocity());
}