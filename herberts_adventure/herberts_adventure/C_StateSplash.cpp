/* Include header files here. */
/* Application. */
#include "C_StateSplash.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_StateSplash::C_StateSplash(sf::RenderWindow& window)
{
	/* Initialising pointer attributes. */
	window_ = new sf::RenderWindow();

	/* Initialising attributes. */
	window_ = &window;
	sf::Texture* indie_jay = new sf::Texture();
	
	/* Setup the splash screen image. */
	if (!indie_jay->loadFromFile("../assets/art/indie_jay_splash_screen_1080px.png"))
	{
		/* Exit the application. */
		exit(-1);
	}

	/* Set the texture to the splash screen image. */
	sprite_.setTexture(*indie_jay);
}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_StateSplash::~C_StateSplash()
{}

/*

	Overview
	========
	This method will provide a way for each state to transition into other states,
	usually based on input.

	Returns
	=======
	C_State* new_state	-	This will return the new state that the state machine should
							transition to.

*/
C_State* C_StateSplash::HandleTransitions()
{
	/* If the timer has finished. */
	if (timer_.Finished())
	{
		/* Go to the title state. */
		return nullptr;
	}

	/* Otherwise, there are no state transitions. */
	return nullptr;
}

/*

	Overview
	========
	Here we will provide a definition for what happens when you enter this state.

*/
void C_StateSplash::OnEnter()
{
	/* Setup the splash screen timer. */
	timer_.set_time(4.0f);
	timer_.start();
}

/*

	Overview
	========
	Here we will provide a definition for what happens when you exit this state.

*/
void C_StateSplash::OnExit()
{}

/*

	Overview
	========
	This is where the states will render their elements using the render window.

*/
void C_StateSplash::Render()
{
	/* Draw elements. */
	window_->draw(sprite_);
}

/*

	Overview
	========
	This method will update every frame.

	Params
	======
	float& dt			-	Delta time used to determine how much time passed since
							the last frame update.

*/
void C_StateSplash::Update(float& dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);
}