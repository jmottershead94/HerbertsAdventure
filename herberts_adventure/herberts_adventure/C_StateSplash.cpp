/* Include header files here. */
/* Application. */
#include "C_StateSplash.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

	Params
	======
	sf::RenderWindow* window	-	Provides access to the main render window in the application class.

	sf::Font* font				-	Provides access to the main font in the application class.

*/
C_StateSplash::C_StateSplash(sf::RenderWindow* window, sf::Font* font, C_World* world)
{
	/* Initialising pointer attributes. */
	window_ = new sf::RenderWindow();
	ui_bg_ = new sf::Texture();

	/* Initialising attributes. */
	window_ = window;
	font_ = font;
	world_ = world;
	input_delay_.set_time(0.5f);
	
	/* If the resources have not loaded. */
	if (!LoadResources())
	{
		/* Exit the application. */
		exit(-1);
	}
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
	This method will load in common resources.

	Returns
	=======
	boolean true/false	-	If the assets have loaded or not.

*/
bool C_StateSplash::LoadResources()
{
	/* The current loaded status of the assets. */
	bool loaded = true;

	main_theme_music_ = new sf::Music();

	/* Load the assets. */
	//loaded &= font_.loadFromFile("../assets/art/FNT_heygorgeous.ttf");
	loaded &= ui_bg_->loadFromFile("../assets/art/SPR_swamp.png");
	loaded &= main_theme_music_->openFromFile("../assets/audio/AUD_main_theme.ogg");

	/* Set the texture of the background UI sprite. */
	ui_bg_sprite_.setTexture(*ui_bg_);
	main_theme_music_->setLoop(true);
	main_theme_music_->setVolume(C_Options::MusicVolume() * C_Options::MasterVolume());

	/* Let the application know if the assets have been loaded. */
	return loaded;
}

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
	/* If the timer has finished OR if the user clicks the left mouse button OR presses the space bar. */
	if (timer_.Finished() || sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		/* Go to the title state. */
		return new C_StateTitle(*this);
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
	/* Initialising a new texture for the splash screen image. */
	sf::Texture* indie_jay = new sf::Texture();

	/* Setup the splash screen timer. */
	timer_.set_time(4.0f);
	timer_.start();

	/* If the splash screen image cannot be loaded correctly. */
	if (!indie_jay->loadFromFile("../assets/art/SPR_indie_jay_splash_screen_1080px.png")
		|| !sfx_buffer_.loadFromFile("../assets/audio/AUD_splash_screen_sound_effect.ogg"))
	{
		/* Exit the application. */
		exit(-1);
	}

	/* Set the texture to the splash screen image. */
	sprite_.setTexture(*indie_jay);

	/* Setup the sound */
	sfx_.setBuffer(sfx_buffer_);
	sfx_.setVolume(10.0f);

	/* Play the sound effect. */
	sfx_.play();
}

/*

	Overview
	========
	Here we will provide a definition for what happens when you exit this state.

*/
void C_StateSplash::OnExit()
{
	main_theme_music_->play();
}

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
	float& dt	-	Delta time used to determine how much time passed since
					the last frame update.

*/
void C_StateSplash::Update(float& dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);
}