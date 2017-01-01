/*

	State Options Class
	===================

	Created:	16th December 2016
	Filter:		State Machine
	Class Name:	C_StateOptions
	Base Class:	C_State
	Author:		Jason Mottershead

	Purpose:	This state will take care of handling options specific functionality
				and rendering.

				This class will display the options screen and allow the user to
				navigate to the main menu.

*/

/* Header guard. */
#ifndef _C_STATEOPTIONS_H_
#define _C_STATEOPTIONS_H_

/* Include header files here. */
/* Application. */
#include "C_State.h"
#include "C_StateMenu.h"
#include "C_Toggle.h"
#include "C_Slider.h"

/* State credits IS A state, therefore inherits from it. */
class C_StateOptions : public C_State
{
	public:
		/* Methods. */
		C_StateOptions(const C_State& current_state);
		~C_StateOptions();
		C_State* HandleTransitions();
		void OnEnter();
		void OnExit();
		void RenderGameOptions();
		void RenderDisplayOptions();
		void RenderSoundOptions();
		void Render();
		void HandleGameOptionUpdates(float& dt);
		void HandleDisplayOptionUpdates(float& dt);
		void HandleSoundOptionUpdates(float& dt);
		void Update(float& dt);

	private:
		/* Attributes. */
		sf::Text display_fps_text_, display_fps_additional_text_;																/* The text used to display the option for display fps information. */
		sf::Text vsync_text_, vsync_additional_text_, fps_text_, fps_additional_text_;
		sf::Text master_volume_text_, music_volume_text_, sfx_volume_text_;
		sf::Text master_volume_value_text_, music_volume_value_text_, sfx_volume_value_text_;
		C_Button button_game_, button_display_, button_sound_;									/* The buttons used for the different application options. */
		C_Button button_menu_;																	/* The button used to navigate back to the main menu. */
		C_Toggle toggle_fps_, toggle_locked_fps_;
		C_Toggle toggle_vsync_;																	/* . */
		C_Slider slider_master_volume_, slider_music_volume_, slider_sfx_volume_;				/* . */
};

#endif