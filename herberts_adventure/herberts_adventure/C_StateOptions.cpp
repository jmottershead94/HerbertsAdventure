/* Include header files here. */
/* Application. */
#include "C_StateOptions.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_StateOptions::C_StateOptions(const C_State& current_state) : C_State(current_state)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_StateOptions::~C_StateOptions()
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
C_State* C_StateOptions::HandleTransitions()
{
	/* If the input delay timer has finished. */
	if (input_delay_.Finished())
	{
		/* If the user clicks the left mouse button OR presses the space bar. */
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			/* If the user clicked on the menu button. */
			if (button_menu_.is_mouse_over())
			{
				/* Go to the main menu. */
				return new C_StateMenu(*this);
			}
		}
	}

	/* Otherwise, there are no state transitions. */
	return nullptr;
}

/*

	Overview
	========
	Here we will provide a definition for what happens when you enter this state.

*/
void C_StateOptions::OnEnter()
{
	C_Utilities::SetText(title_text_, *font_, "Options", 100, sf::Vector2f(window_->getSize().x * 0.5f, window_->getSize().y * 0.25f));
	C_Utilities::SetText(display_fps_text_, *font_, "Display FPS", 20, sf::Vector2f(window_->getSize().x * 0.35f, window_->getSize().y * 0.5f));
	C_Utilities::SetText(display_option_text_, *font_, "Display Option Example", 20, sf::Vector2f(window_->getSize().x * 0.35f, window_->getSize().y * 0.5f));
	C_Utilities::SetText(sound_option_text_, *font_, "Sound Option Example", 20, sf::Vector2f(window_->getSize().x * 0.35f, window_->getSize().y * 0.5f));

	/* Initialising local attributes. */
	button_game_.Init(window_, font_, "Game", 50, sf::Vector2f(window_->getSize().x * 0.25f, window_->getSize().y * 0.4f));
	button_display_.Init(window_, font_, "Display", 50, sf::Vector2f(window_->getSize().x * 0.5f, window_->getSize().y * 0.4f));
	button_sound_.Init(window_, font_, "Sound", 50, sf::Vector2f(window_->getSize().x * 0.75f, window_->getSize().y * 0.4f));
	button_menu_.Init(window_, font_, "Back", 50, sf::Vector2f(window_->getSize().x * 0.8f, window_->getSize().y * 0.9f));

	toggle_fps_.Init(window_, font_, sf::Vector2f(window_->getSize().x * 0.65f, window_->getSize().y * 0.45f));

	/* Start with the game options displayed. */
	button_game_.set_clicked(true);

	/* Start the input delay timer. */
	input_delay_.start();
}

/*

	Overview
	========
	Here we will provide a definition for what happens when you exit this state.

*/
void C_StateOptions::OnExit()
{}

void C_StateOptions::RenderGameOptions()
{	
	window_->draw(display_fps_text_);
	window_->draw(toggle_fps_);
	//toggle_fps_.Render();
}

void C_StateOptions::RenderDisplayOptions()
{
	window_->draw(display_option_text_);
}

void C_StateOptions::RenderSoundOptions()
{
	window_->draw(sound_option_text_);
}

/*

	Overview
	========
	This is where the states will render their elements using the render window.

*/
void C_StateOptions::Render()
{
	/* Draw elements. */
	window_->draw(ui_bg_sprite_);
	window_->draw(title_text_);
	button_game_.Render();
	button_display_.Render();
	button_sound_.Render();
	button_menu_.Render();

	if (button_game_.clicked_on())
	{
		RenderGameOptions();
	}

	if (button_display_.clicked_on())
	{
		RenderDisplayOptions();
	}

	if (button_sound_.clicked_on())
	{
		RenderSoundOptions();
	}

	/* If the user pressed the left mouse button. */
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (button_game_.is_mouse_over())
		{
			button_game_.set_clicked(true);
			button_display_.set_clicked(false);
			button_sound_.set_clicked(false);
		}

		if (button_display_.is_mouse_over())
		{
			button_game_.set_clicked(false);
			button_display_.set_clicked(true);
			button_sound_.set_clicked(false);
		}

		if (button_sound_.is_mouse_over())
		{
			button_game_.set_clicked(false);
			button_display_.set_clicked(false);
			button_sound_.set_clicked(true);
		}
	}
	
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
void C_StateOptions::Update(float& dt)
{
	/* Update attributes. */
	button_game_.Update(dt);
	button_display_.Update(dt);
	button_sound_.Update(dt);
	button_menu_.Update(dt);

	if (button_game_.clicked_on())
	{
		toggle_fps_.Update(dt);
	}
}