#ifndef _C_BUTTON_H_
#define _C_BUTTON_H_

#include "C_UIElement.h"

class C_Button : public C_UIElement
{
	public:
		/* Methods. */
		C_Button();
		~C_Button();
		void Init(sf::RenderWindow* window, sf::Font* font, const std::string message, const unsigned int size, const sf::Vector2f position);
		void Render();
		void Update(float& dt);

		/* Getters. */
		/* This will allow us to see if the mouse cursor is over the button. */
		inline bool is_mouse_over() { return (text_.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y)); }

	protected:
		/* Methods. */
		void InFocusResponse();
		void OutOfFocusResponse();

	private:
		/* Attributes. */
		sf::Text text_;										/* The text that will be displayed to describe the button. */
		sf::Color original_colour_, highlighted_colour_;
		unsigned int original_scale_, highlighted_scale_;
};

#endif