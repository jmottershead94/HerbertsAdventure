/*

	Button Class
	============

	Created:	19th December 2016
	Filter:		UI
	Class Name:	C_Button
	Base Class: C_UIElement
	Author:		Jason Mottershead

	Purpose:	Button will provide a way for the user to interact with UI elements via mouse
				clicks, and provide a basic button system that will clearly show if the user
				is highlighting the button or not.

*/

/* Header guard. */
#ifndef _C_BUTTON_H_
#define _C_BUTTON_H_

/* Include header files here. */
/* Application. */
#include "C_UIElement.h"

/* Button IS A UI element, therefore inherits from it. */
class C_Button : public C_UIElement
{
	public:
		/* Methods. */
		C_Button();
		~C_Button();
		void Init(sf::RenderWindow* window, sf::Font* font, const std::string message, const unsigned int size, const sf::Vector2f position);
		void Render();
		void Update(float& dt);

		/* Getters / Setters. */
		/* This will allow us to see if the mouse cursor is over the button. */
		inline const bool is_mouse_over() { return (text_.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y)); }

		/* This will allow us to see if the button is interactable. */
		inline const bool& is_interactable() { return (interactable_);  }

		/* This will allow us to set the button as interactable or not. */
		inline void set_interactable(const bool value) { interactable_ = value; }

	protected:
		/* Methods. */
		void InFocusResponse();
		void OutOfFocusResponse();

	private:
		/* Attributes. */
		unsigned int original_scale_, highlighted_scale_;	/* This will be used to scale the button up/down. */
		bool interactable_;									/* If this button is interactable. */
		sf::Text text_;										/* The text that will be displayed to describe the button. */
		sf::Color original_colour_, highlighted_colour_;	/* This will be used to change the colour depending if the user is hovering the mouse over the button. */
};

#endif