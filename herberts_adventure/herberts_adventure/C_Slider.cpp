#include "C_Slider.h"

C_Slider::C_Slider() :
	interactable_(true),
	is_checked_(false),
	just_changed_(false),
	value_(100.0f)
{}

C_Slider::~C_Slider()
{}

void C_Slider::Init(sf::RenderWindow * window, sf::Font* font, const sf::Vector2f position, size_t amount_of_options, sf::Vector2f range)
{
	/* Handles base UI element initialisation. */
	C_UIElement::Init(window, font);

	/* Loading a texture. */
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../assets/art/SPR_ui.png");
	amount_of_options_ = amount_of_options;
	range_ = range;

	for (size_t i = 0; i < amount_of_options_; i++)
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
			value_ = (float)(index + 1) * (range_.y / amount_of_options_);
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

		for (size_t i = 0; i < amount_of_options_; i++)
		{
			CheckSlider(sprites_.at(i), i);
		}
	}

	if (value_ >= range_.x)
	{
		for (size_t i = 0; i < (size_t)(value_ * (amount_of_options_ / range_.y)); i++)
		{
			sprites_.at(i).setTextureRect(sf::IntRect(128, 0, 128, 128));
		}
	}

	if (value_ <= range_.y)
	{
		for (size_t i = (size_t)(value_ * (amount_of_options_ / range_.y)); i < sprites_.size(); i++)
		{
			sprites_.at(i).setTextureRect(sf::IntRect(0, 0, 128, 128));
		}
	}
	
}

void C_Slider::InFocusResponse()
{}

void C_Slider::OutOfFocusResponse()
{}