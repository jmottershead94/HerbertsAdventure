/* Include header files here. */
/* Application. */
#include "C_StateMenu.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_StateMenu::C_StateMenu(const C_State& current_state) : C_State(current_state)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_StateMenu::~C_StateMenu()
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
C_State* C_StateMenu::HandleTransitions()
{
	/* If the input delay timer has finished. */
	if (input_delay_.Finished())
	{
		/* If the user pressed the left mouse button. */
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			/* If the user clicked on the play button. */
			if (button_play_.is_mouse_over())
			{
				/* Go to the game. */
				return new C_StateGame(*this);
			}

			/* If the user clicked on the options button. */
			if (button_options_.is_mouse_over())
			{
				/* Go to the options state. */
				return new C_StateOptions(*this);
			}

			/* If the user clicked on the credits button. */
			if (button_credits_.is_mouse_over())
			{
				/* Go to credits. */
				return new C_StateCredits(*this);
			}

			/* If the user clicked on the quit button. */
			if (button_quit_.is_mouse_over())
			{
				/* Close the window. */
				window_->close();
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
void C_StateMenu::OnEnter()
{
	C_Utilities::SetText(title_text_, *font_, "Herbert's Adventure!", 100, sf::Vector2f(window_->getSize().x * 0.5f, window_->getSize().y * 0.25f));

	/* Initialising local attributes. */
	button_play_.Init(window_, font_, "Play!", 50, sf::Vector2f(window_->getSize().x * 0.2f, window_->getSize().y * 0.65f));
	button_options_.Init(window_, font_, "Options", 50, sf::Vector2f(window_->getSize().x * 0.4f, window_->getSize().y * 0.65f));
	button_credits_.Init(window_, font_, "Credits", 50, sf::Vector2f(window_->getSize().x * 0.6f, window_->getSize().y * 0.65f));
	button_quit_.Init(window_, font_, "Quit", 50, sf::Vector2f(window_->getSize().x * 0.8f, window_->getSize().y * 0.65f));

	/* Start the input delay timer. */
	input_delay_.start();
}

/*

	Overview
	========
	Here we will provide a definition for what happens when you exit this state.

*/
void C_StateMenu::OnExit()
{}

/*

	Overview
	========
	This is where the states will render their elements using the render window.

*/
void C_StateMenu::Render()
{
	/* Draw elements. */
	window_->draw(ui_bg_sprite_);
	window_->draw(title_text_);
	button_play_.Render();
	button_options_.Render();
	button_credits_.Render();
	button_quit_.Render();
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
void C_StateMenu::Update(float& dt)
{
	/* Update attributes. */
	button_play_.Update(dt);
	button_options_.Update(dt);
	button_credits_.Update(dt);
	button_quit_.Update(dt);
}
