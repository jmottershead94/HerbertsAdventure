#include "C_Toggle.h"

C_Toggle::C_Toggle() :
	interactable_(true),
	is_checked_(false),
	just_changed_(false)
{}

C_Toggle::~C_Toggle()
{}

void C_Toggle::Init(sf::RenderWindow * window, sf::Font* font, const sf::Vector2f position)
{
	/* Handles base UI element initialisation. */
	C_UIElement::Init(window, font);

	/* Loading a texture. */
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../assets/art/SPR_ui.png");

	/* Initialising the game object. */
	setTexture(*texture);
	setTextureRect(sf::IntRect(0, 0, 128, 128));
	setPosition(position);
	setRotation(0.0f);
	setScale(sf::Vector2f(1.0f, 1.0f));	
}

void C_Toggle::Render()
{
	//window_->draw(sprite_);
}

void C_Toggle::Update(float & dt)
{
	UNUSED(dt);

	if (interactable_)
	{
		/* Handles base UI element updates. */
		C_UIElement::Update(dt);
		
		if (is_mouse_over())
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
			if (is_mouse_over() && !just_changed_)
			{
				if (!is_checked_)
				{
					/* Set the clicked on flag to true. */
					is_checked_ = true;
				}
				else
				{
					is_checked_ = false;
				}

				just_changed_ = true;
			}
		}
	}
}

void C_Toggle::InFocusResponse()
{
	if (is_checked_)
	{
		if (getTextureRect() != sf::IntRect(128, 128, 128, 128))
		{
			setTextureRect(sf::IntRect(128, 128, 128, 128));
		}
	}
	else
	{
		if (getTextureRect() != sf::IntRect(0, 128, 128, 128))
		{
			setTextureRect(sf::IntRect(0, 128, 128, 128));
		}
	}
}

void C_Toggle::OutOfFocusResponse()
{
	if (is_checked_)
	{
		if (getTextureRect() != sf::IntRect(128, 0, 128, 128))
		{
			setTextureRect(sf::IntRect(128, 0, 128, 128));
		}
	}
	else
	{
		if (getTextureRect() != sf::IntRect(0, 0, 128, 128))
		{
			setTextureRect(sf::IntRect(0, 0, 128, 128));
		}
	}
}