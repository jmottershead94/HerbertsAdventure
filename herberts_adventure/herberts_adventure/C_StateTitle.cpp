/* Include header files here. */
/* Application. */
#include "C_StateTitle.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_StateTitle::C_StateTitle(const C_State& current_state) : C_State(current_state)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_StateTitle::~C_StateTitle()
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
C_State* C_StateTitle::HandleTransitions()
{
	/* If the input delay timer has finished. */
	if (input_delay_.Finished())
	{
		/* If the user clicks the left mouse button. */
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			/* Go to the main menu. */
			return new C_StateMenu(*this);
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
void C_StateTitle::OnEnter()
{
	C_Utilities::SetText(title_text_, *font_, "Herbert's Adventure!", 100, sf::Vector2f(window_->getSize().x * 0.5f, window_->getSize().y * 0.25f));
	C_Utilities::SetText(message_, *font_, "Click Anywhere!", 50, sf::Vector2f(window_->getSize().x * 0.5f, window_->getSize().y * 0.5f));

	/* Start the input delay timer. */
	input_delay_.start();
}

/*

	Overview
	========
	Here we will provide a definition for what happens when you exit this state.

*/
void C_StateTitle::OnExit()
{}

/*

	Overview
	========
	This is where the states will render their elements using the render window.

*/
void C_StateTitle::Render()
{
	/* Draw elements. */
	window_->draw(ui_bg_sprite_);
	window_->draw(title_text_);
	window_->draw(message_);
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
void C_StateTitle::Update(float& dt)
{
	/* To avoid warnings as errors, dt will be used later. */
	UNUSED(dt);
}
