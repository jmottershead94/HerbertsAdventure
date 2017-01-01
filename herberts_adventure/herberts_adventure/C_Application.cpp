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
	window_.create(sf::VideoMode(screen_resolution_.x, screen_resolution_.y), "Herberts Adventure", sf::Style::Fullscreen);
	//window_.create(sf::VideoMode(screen_resolution_.x, screen_resolution_.y), "Herberts Adventure", sf::Style::Default);
	camera_.Init(&window_, sf::FloatRect(0.0f, 0.0f, 1920.0f, 1080.0f));
	utilities_.Init();
	options_.Init();
	debug_.Init();

	window_.setView(camera_);

	/* If the main font file does not load. */
	if (!font_.loadFromFile("../assets/art/FNT_heygorgeous.ttf"))
	{
		/* Exit the application. */
		exit(-1);
	}

	/* Defining how much gravity there is. */
	sf::Vector2f gravity(0.0f, -10.0f);

	/* Creating the Box2D world. */
	world_ = new C_World();
	world_->Init(gravity);

	/* Starting the state machine. */
	current_state_ = new C_StateSplash(&window_, &font_, world_, &camera_);
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
	options_.CleanUp();
	CLEANUPDELETE(current_state_);
	DELETE(world_);
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

	/* Update the view of the application with the camera. */
	window_.setView(camera_);

	/* Render application stuff here... */
	current_state_->Render();

	if (C_Options::DisplayFPS())
	{
		/* Keeps the FPS counter in the bottom right of the screen, so it follows the camera wherever it goes. */
		fps_counter_.setPosition(sf::Vector2f(camera_.getCenter().x + (camera_.viewport().width * 0.4f), camera_.getCenter().y + (camera_.viewport().height * 0.45f)));

		/* Display the fps. */
		window_.draw(fps_counter_);
	}

	if (C_Options::LockFPS())
	{
		/* Try and lock to 60 fps. */
		window_.setFramerateLimit(kFrameRate);
	}
	else
	{
		/* Remove the fps limit. */
		window_.setFramerateLimit(0);
	}
	
	if (C_Options::UseVSync())
	{
		window_.setVerticalSyncEnabled(true);
	}
	else
	{
		window_.setVerticalSyncEnabled(false);
	}

	/* Display the new render window layout. */
	window_.display();
}

/*

	Overview
	========
	This method will setup the fps counter text.

	Params
	======
	float& dt			-	Delta time used to determine how much time passed since
							the last frame update.

*/
void C_Application::SetUpFPS(float& dt)
{
	/* Assign fps value. */
	fps_ = 1.0f / dt;

	/* Set the fps text. */
	C_Utilities::SetText(fps_counter_, font_, "FPS: " + C_Utilities::FloatToString(2, fps_), 20, sf::Vector2f(window_.getSize().x * 0.9f, window_.getSize().y * 0.99f), C_Utilities::TextAlignment::centre);
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
	/* Calculate and setup the FPS text. */
	SetUpFPS(dt);
	
	//int32 velocity_iterations = 6;
	//int32 position_iterations = 2;

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

	/* Updates the physics engine. */
	//world_->Step(fps_, velocity_iterations, position_iterations);
	world_->Update(dt);

	/* This update has been successful. */
	return true;
}