#include "C_Sprite.h"

C_Sprite::C_Sprite()
{}

C_Sprite::~C_Sprite()
{}

void C_Sprite::Init(sf::RenderWindow * window, sf::Font* font, const sf::Vector2f position, const sf::IntRect texture_coordinates)
{
	/* Handles base UI element initialisation. */
	C_UIElement::Init(window, font);

	/* Loading a texture. */
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../assets/art/SPR_ui.png");

	/* Initialising the game object. */
	setTexture(*texture);
	//setTextureRect(sf::IntRect(0, 0, 128, 128));
	setTextureRect(texture_coordinates);
	setPosition(position);
	setRotation(0.0f);
	setScale(sf::Vector2f(1.0f, 1.0f));
}

void C_Sprite::Update(float& dt)
{
	/* Handles base UI element updates. */
	C_UIElement::Update(dt);
}

void C_Sprite::InFocusResponse()
{}

void C_Sprite::OutOfFocusResponse()
{}