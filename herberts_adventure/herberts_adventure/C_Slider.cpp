#include "C_Slider.h"

C_Slider::C_Slider() :
	interactable_(true),
	is_checked_(false),
	just_changed_(false),
	value_(100.0f)
{}

C_Slider::~C_Slider()
{}

void C_Slider::Init(sf::RenderWindow * window, sf::Font* font, const sf::Vector2f position)
{
	/* Handles base UI element initialisation. */
	C_UIElement::Init(window, font);

	/* Loading a texture. */
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../assets/art/SPR_ui.png");

	for (size_t i = 0; i < sprites_.size(); i++)
	{
		sprites_.at(i).setTexture(*texture);
		sprites_.at(i).setTextureRect(sf::IntRect(0, 0, 128, 128));
		sprites_.at(i).setPosition(position + sf::Vector2f(i * 40.0f, 0.0f));
		sprites_.at(i).setRotation(0.0f);
		sprites_.at(i).setScale(sf::Vector2f(0.4f, 0.4f));
	}
}

void C_Slider::CheckSlider(sf::Sprite& sprite, int index)
{
	if (is_mouse_over(sprite))
	{
		/* It is in focus. */
		set_focus(true);

		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (just_changed_)
			{
				just_changed_ = false;
			}
		}
	}
	else
	{
		set_focus(false);

		if (just_changed_)
		{
			just_changed_ = false;
		}
	}

	/* If the user pressed the left mouse button. */
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (is_mouse_over(sprite) && !just_changed_)
		{
			value_ = (float)(index + 1) * 10.0f;
			just_changed_ = true;
		}
	}
}

void C_Slider::Update(float& dt)
{
	if (interactable_)
	{
		/* Handles base UI element updates. */
		C_UIElement::Update(dt);

		for (size_t i = 0; i < sprites_.size(); i++)
		{
			CheckSlider(sprites_.at(i), i);
		}
	}

	if (value_ >= 0.0f)
	{
		for (size_t i = 0; i < (size_t)(value_ * 0.1f); i++)
		{
			sprites_.at(i).setTextureRect(sf::IntRect(128, 0, 128, 128));
		}
	}

	if (value_ <= 100.0f)
	{
		for (size_t i = (size_t)(value_ * 0.1f); i < sprites_.size(); i++)
		{
			sprites_.at(i).setTextureRect(sf::IntRect(0, 0, 128, 128));
		}
	}
	
}

void C_Slider::InFocusResponse()
{}

void C_Slider::OutOfFocusResponse()
{}