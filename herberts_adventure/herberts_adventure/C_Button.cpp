/* Include header files here. */
/* Application. */
#include "C_Button.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Button::C_Button() :
	original_scale_(0),
	highlighted_scale_(0),
	interactable_(true)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_Button::~C_Button()
{}

/*

	Overview
	========
	This method will initialise specific attribute values.

	Params
	======
	sf::RenderWindow* window	-	Provides access to the main render window in the application class.

	sf::Font* font				-	Provides access to the main font in the state machine.

	const std::string message	-	The text that will be displayed for this button.

	const unsigned int size		-	The original size of the text for the button.

	const sf::Vector2f position	-	The position of the button.

*/
void C_Button::Init(sf::RenderWindow* window, sf::Font* font, const std::string message, const unsigned int size, const sf::Vector2f position)
{
	/* Handles base UI element initialisation. */
	C_UIElement::Init(window, font);

	/* Initialising local attributes. */
	C_Utilities::SetText(text_, *font, message, size, position);
	original_colour_ = text_.getFillColor();
	original_scale_ = size;
	highlighted_colour_ = sf::Color::Red;
	highlighted_scale_ = original_scale_ + 10;
}

/*

	Overview
	========
	This method will draw the button.

*/
void C_Button::Render()
{
	/* Draw the button. */
	window_->draw(text_);
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
void C_Button::Update(float& dt)
{
	/* If the button is interactable. */
	if(interactable_)
	{
		/* Handles base UI element updates. */
		C_UIElement::Update(dt);

		/* If the mouse is over this button. */
		if (is_mouse_over())
		{
			/* It is in focus. */
			set_focus(true);
		}
		/* Otherwise, the mouse is not over this button. */
		else
		{
			/* It is no longer in focus. */
			set_focus(false);
		}
	}
}

/*

	Overview
	========
	This method will provide the response for the button being in focus.

*/
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

/*

	Overview
	========
	This method will provide the response for the button being out of focus.

*/
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
