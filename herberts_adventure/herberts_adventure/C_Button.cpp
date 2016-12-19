#include "C_Button.h"

C_Button::C_Button()
{}

C_Button::~C_Button()
{}

void C_Button::Init(sf::RenderWindow* window, sf::Font* font, const std::string message, const unsigned int size, const sf::Vector2f position)
{
	/* Handles base UI element initialisation. */
	C_UIElement::Init(window, font);

	/* Initialising local attributes. */
	C_Utilities::SetText(text_, *font, message, size, position);
	original_colour_ = text_.getFillColor();
	original_scale_ = size;
	highlighted_colour_ = sf::Color::Red;
	highlighted_scale_ = original_scale_ + 15;
}

void C_Button::Render()
{
	window_->draw(text_);
}

void C_Button::Update(float& dt)
{
	C_UIElement::Update(dt);

	if (is_mouse_over())
	{
		set_focus(true);
	}
	else
	{
		set_focus(false);
	}
}

void C_Button::InFocusResponse()
{
	/* Scale up button and change to highlighted colour. */
	if (text_.getCharacterSize() != highlighted_scale_)
	{
		text_.setCharacterSize(highlighted_scale_);
	}

	if(text_.getFillColor() != highlighted_colour_)
	{
		text_.setFillColor(highlighted_colour_);
	}
}

void C_Button::OutOfFocusResponse()
{
	/* Scale back down and change back to original colour. */
	if (text_.getCharacterSize() != original_scale_)
	{
		text_.setCharacterSize(original_scale_);
	}

	if (text_.getFillColor() != original_colour_)
	{
		text_.setFillColor(original_colour_);
	}
}
