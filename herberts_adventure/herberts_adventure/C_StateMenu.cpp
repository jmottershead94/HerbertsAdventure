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
std::unique_ptr<C_State> C_StateMenu::HandleTransitions()
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
				ui_sfx_->play();

				/* Go to the game. */
				return std::make_unique<C_StateGame>(*this);
			}

			/* If the user clicked on the options button. */
			if (button_options_.is_mouse_over())
			{
				ui_sfx_->play();

				/* Go to the options state. */
				return std::make_unique<C_StateOptions>(*this);
			}

			/* If the user clicked on the credits button. */
			if (button_credits_.is_mouse_over())
			{
				ui_sfx_->play();

				/* Go to credits. */
				return std::make_unique<C_StateCredits>(*this);
			}

			/* If the user clicked on the quit button. */
			if (button_quit_.is_mouse_over())
			{
				ui_sfx_->play();

				/* Close the window. */
				window_->close();
			}
		}

		if (sf::Joystick::isConnected(0))
		{
			/* If the user clicked on the play button. */
			if (C_Input::APressed())
			{
				ui_sfx_->play();

				/* Go to the game. */
				return std::make_unique<C_StateGame>(*this);
			}

			/* If the user clicked on the options button. */
			if (C_Input::XPressed())
			{
				ui_sfx_->play();

				/* Go to the options state. */
				return std::make_unique<C_StateOptions>(*this);
			}

			/* If the user clicked on the credits button. */
			if (C_Input::YPressed())
			{
				ui_sfx_->play();

				/* Go to credits. */
				return std::make_unique<C_StateCredits>(*this);
			}

			/* If the user clicked on the quit button. */
			if (C_Input::BPressed())
			{
				ui_sfx_->play();

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
	C_Utilities::SetText(title_text_, *font_, "Herbert's Adventure!", 100, sf::Vector2f(window_->getSize().x * 0.5f, window_->getSize().y * 0.25f), C_Utilities::TextAlignment::centre);

	/* Initialising local attributes. */
	button_play_.Init(window_, font_, "Play!", 50, sf::Vector2f(window_->getSize().x * 0.2f, window_->getSize().y * 0.65f));
	button_options_.Init(window_, font_, "Options", 50, sf::Vector2f(window_->getSize().x * 0.4f, window_->getSize().y * 0.65f));
	button_credits_.Init(window_, font_, "Credits", 50, sf::Vector2f(window_->getSize().x * 0.6f, window_->getSize().y * 0.65f));
	button_quit_.Init(window_, font_, "Quit", 50, sf::Vector2f(window_->getSize().x * 0.8f, window_->getSize().y * 0.65f));

	spr_A_.Init(window_, font_, sf::Vector2f(window_->getSize().x * 0.1675f, window_->getSize().y * 0.675f), sf::IntRect(256, 0, 128, 128));
	spr_X_.Init(window_, font_, sf::Vector2f(window_->getSize().x * 0.37f, window_->getSize().y * 0.675f), sf::IntRect(256, 384, 128, 128));
	spr_Y_.Init(window_, font_, sf::Vector2f(window_->getSize().x * 0.57f, window_->getSize().y * 0.675f), sf::IntRect(256, 256, 128, 128));
	spr_B_.Init(window_, font_, sf::Vector2f(window_->getSize().x * 0.775f, window_->getSize().y * 0.675f), sf::IntRect(256, 128, 128, 128));

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

	if (sf::Joystick::isConnected(0))
	{
		window_->draw(spr_A_);
		window_->draw(spr_B_);
		window_->draw(spr_X_);
		window_->draw(spr_Y_);
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
void C_StateMenu::Update(float& dt)
{
	/* Update attributes. */
	button_play_.Update(dt);
	button_options_.Update(dt);
	button_credits_.Update(dt);
	button_quit_.Update(dt);
}
