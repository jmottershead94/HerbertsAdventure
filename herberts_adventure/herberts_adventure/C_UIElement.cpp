#include "C_UIElement.h"

C_UIElement::C_UIElement() :
	in_focus_(false)
{}

C_UIElement::~C_UIElement()
{}

void C_UIElement::Init(sf::RenderWindow* window, sf::Font* font)
{
	/* Initialising local attributes. */
	window_ = window;
	font_ = font;
}

void C_UIElement::Update(float& dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);

	if (in_focus_)
	{
		InFocusResponse();
	}
	else
	{
		OutOfFocusResponse();
	}
}