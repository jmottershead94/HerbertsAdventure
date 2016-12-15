/* Include header files here. */
/* Application. */
#include "C_Application.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Application::C_Application()
{}

/*

	Overview
	========
	This method will initialise specific attribute values.

	Params
	======
	const sf::Vector2i screen_resolution	-	This will allow the main.cpp to specify the resolution of the 
												render window used for this application.

*/
void C_Application::Init(const sf::Vector2i screen_resolution)
{
	/* Initialising local attributes. */
	screen_resolution_ = screen_resolution;
	window_.create(sf::VideoMode(screen_resolution_.x, screen_resolution_.y), "Herberts Adventure");
	window_.setFramerateLimit(kFrameRate);
	utilities_.Init();
}

/*

	Overview
	========
	Here we will clean up any pointer attributes in this class.

*/
void C_Application::CleanUp()
{
	/* Clean up attribute values. */
	utilities_.CleanUp();
}

/*

	Overview
	========
	Here we will handle the state machine, and this method will handle the
	different state transitions.

*/
void C_Application::HandleStates()
{}

/*

	Overview
	========
	This will provide access to standard application controls, such as 
	exiting the application at anytime (and possibly debug options in 
	the future).

*/
void C_Application::Controls()
{
	/* If the escape key has been pressed. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		/* Clean up the application. */
		CleanUp();

		/* Close the window. */
		window_.close();
	}
}

/*

	Overview
	========
	This method will render all of the application elements.

*/
void C_Application::Render()
{
	/* Clear the current render window. */
	window_.clear();

	/* Render application stuff here... */


	/* Display the new render window layout. */
	window_.display();
}

/*

	Overview
	========
	This method will update every frame.

	Params
	======
	float dt			-	Delta time used to determine how much time passed since
							the last frame update.

	Returns
	=======
	boolean true/false	-	Performed a successful update.

*/
bool C_Application::Update(float dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);

	/* While the window is checking for events. */
	while (window_.pollEvent(event_))
	{
		/* If the user is closing the window. */
		if (event_.type == sf::Event::Closed)
		{
			/* Clean up the application. */
			CleanUp();

			/* Close the window. */
			window_.close();
		}
	}

	/* Handles any state machine changes. */
	HandleStates();

	/* Handles any generic application controls. */
	Controls();

	/* Update application attributes here... */


	/* This update has been successful. */
	return true;
}