/* Include header files here. */
/* Application. */
#include "C_StateGame.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_StateGame::C_StateGame(const C_State& current_state) : C_State(current_state)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_StateGame::~C_StateGame()
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
C_State* C_StateGame::HandleTransitions()
{
	/* If the input delay timer has finished. */
	if (input_delay_.Finished())
	{
		/* If the user clicks the left mouse button. */
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			ui_sfx_->play();

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
void C_StateGame::OnEnter()
{
	C_Utilities::SetText(title_text_, *font_, "VIDEA GAEM", 100, sf::Vector2f(window_->getSize().x * 0.5f, window_->getSize().y * 0.25f), C_Utilities::TextAlignment::centre);

	/* Start the input delay timer. */
	input_delay_.start();

	/* Initialise the level. */
	level_.Init(world_, camera_, window_);
}

/*

	Overview
	========
	Here we will provide a definition for what happens when you exit this state.

*/
void C_StateGame::OnExit()
{
	camera_->reset(camera_->viewport());

	world_->ClearBodies();
}

/*

	Overview
	========
	This is where the states will render their elements using the render window.

*/
void C_StateGame::Render()
{
	/* Draw elements. */
	window_->draw(ui_bg_sprite_);
	window_->draw(title_text_);

	/* Render level elements. */
	level_.Render();
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
void C_StateGame::Update(float& dt)
{
	/* Handle level updates. */
	level_.Update(dt);
}