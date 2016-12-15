#include "C_Application.h"

C_Application::C_Application()
{}

void C_Application::Init(const sf::Vector2i screen_resolution)
{
	/* Initialising local attributes. */
	screen_resolution_ = screen_resolution;
	window_.create(sf::VideoMode(screen_resolution_.x, screen_resolution_.y), "Herberts Adventure");
	window_.setFramerateLimit(kFrameRate);
}

void C_Application::CleanUp()
{}

void C_Application::HandleStates()
{}

void C_Application::Controls()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		window_.close();
	}
}

void C_Application::Render()
{}

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

	/* Handles any state machine changes. */
	HandleStates();

	/* Handles any generic application controls. */
	Controls();

	/* This update has been successful. */
	return true;
}