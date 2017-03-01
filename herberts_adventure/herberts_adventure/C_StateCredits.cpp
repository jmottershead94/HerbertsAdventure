/* Include header files here. */
/* Application. */
#include "C_StateCredits.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_StateCredits::C_StateCredits(const C_State& current_state) : C_State(current_state)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_StateCredits::~C_StateCredits()
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
std::unique_ptr<C_State> C_StateCredits::HandleTransitions()
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
				ui_sfx_->play();

				/* Go to the main menu. */
				return std::make_unique<C_StateMenu>(*this);
			}
		}
		else if (C_Input::CancelPressed())
		{
			ui_sfx_->play();

			/* Go to the main menu. */
			return std::make_unique<C_StateMenu>(*this);
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
void C_StateCredits::OnEnter()
{
	const std::string splash_sfx_text = "Twinkle Download Link: www.freesound.org/people/fschaeffer/sounds/337949/\nLicense Link: creativecommons.org/licenses/by-nc/3.0/\nCreator: fschaeffer\nChanges : None.";
	const std::string main_music_text = "Short Swing Download Link: www.freesound.org/people/ValentinSosnitskiy/sounds/317463/\nLicense Link: creativecommons.org/licenses/by/3.0/\nCreator: ValentinSosnitskiy\nChanges : None.";

	C_Utilities::SetText(title_text_, *font_, "Credits", 100, sf::Vector2f(window_->getSize().x * 0.5f, window_->getSize().y * 0.25f), C_Utilities::TextAlignment::centre);
	C_Utilities::SetText(splash_sfx_credit_, *font_, splash_sfx_text, 20, sf::Vector2f(window_->getSize().x * 0.35f, window_->getSize().y * 0.45f), C_Utilities::TextAlignment::centre);
	C_Utilities::SetText(main_music_credit_, *font_, main_music_text, 20, sf::Vector2f(window_->getSize().x * 0.4f, window_->getSize().y * 0.6f), C_Utilities::TextAlignment::centre);
	C_Utilities::SetText(developer_credit_, *font_, "Game developed by Jason Mottershead", 20, sf::Vector2f(window_->getSize().x * 0.19f, window_->getSize().y * 0.75f), C_Utilities::TextAlignment::centre);

	/* Initialising local attributes. */
	button_menu_.Init(window_, font_, "Back", 50, sf::Vector2f(window_->getSize().x * 0.8f, window_->getSize().y * 0.9f));

	/* Start the input delay timer. */
	input_delay_.start();
}

/*

	Overview
	========
	Here we will provide a definition for what happens when you exit this state.

*/
void C_StateCredits::OnExit()
{}

/*

	Overview
	========
	This is where the states will render their elements using the render window.

*/
void C_StateCredits::Render()
{
	/* Draw elements. */
	window_->draw(ui_bg_sprite_);
	window_->draw(title_text_);
	window_->draw(splash_sfx_credit_);
	window_->draw(main_music_credit_);
	window_->draw(developer_credit_);
	button_menu_.Render();
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
void C_StateCredits::Update(float& dt)
{
	/* Update attributes. */
	button_menu_.Update(dt);
}