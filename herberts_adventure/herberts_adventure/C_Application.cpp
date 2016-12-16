/* Include header files here. */
/* Application. */
#include "C_Application.h"

/*
	
	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Application::C_Application() :
	current_state_(nullptr)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_Application::~C_Application()
{
	/* Clean up the application. */
	//CleanUp();
}

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
	//window_.create(sf::VideoMode(screen_resolution_.x, screen_resolution_.y), "Herberts Adventure", sf::Style::Fullscreen);
	window_.create(sf::VideoMode(screen_resolution_.x, screen_resolution_.y), "Herberts Adventure", sf::Style::Default);
	window_.setFramerateLimit(kFrameRate);
	utilities_.Init();

	/* Starting the state machine. */
	current_state_ = new C_StateSplash(&window_);
	current_state_->OnEnter();
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
	CLEANUPDELETE(current_state_);
}

/*

	Overview
	========
	Here we will handle the state machine, and this method will handle the
	different state transitions.

*/
void C_Application::HandleStates()
{
	/* Creates a new state if one is required. */
	C_State* new_state = current_state_->HandleTransitions();

	/* If the new state is equal to something. */
	if (new_state != nullptr)
	{
		/* Exit the previous state. */
		current_state_->OnExit();
		DELETE(current_state_);

		/* Enter the new state. */
		current_state_ = new_state;
		current_state_->OnEnter();
	}
}

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
	current_state_->Render();

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
			/* Close the window. */
			window_.close();
		}
	}

	/* Handles any generic application controls. */
	Controls();

	/* Handles any state machine changes. */
	HandleStates();

	/* Update application attributes here... */
	current_state_->Update(dt);

	/* This update has been successful. */
	return true;
}