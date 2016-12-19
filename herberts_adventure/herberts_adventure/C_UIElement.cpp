/* Include header files here. */
/* Application. */
#include "C_UIElement.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_UIElement::C_UIElement() :
	in_focus_(false)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_UIElement::~C_UIElement()
{}

/*

	Overview
	========
	This method will initialise specific attribute values.

	Params
	======
	sf::RenderWindow* window	-	Provides access to the main render window in the application class.

	sf::Font* font				-	Provides access to the main font in the state machine.

*/
void C_UIElement::Init(sf::RenderWindow* window, sf::Font* font)
{
	/* Initialising local attributes. */
	window_ = window;
	font_ = font;
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
void C_UIElement::Update(float& dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);

	/* If the UI element is in focus. */
	if (in_focus_)
	{
		/* Execute the in focus response. */
		InFocusResponse();
	}
	/* Otherwise, the UI element is out of focus. */
	else
	{
		/* Execute the out of focus response. */
		OutOfFocusResponse();
	}
}