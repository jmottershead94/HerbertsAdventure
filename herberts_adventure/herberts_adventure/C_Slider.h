#ifndef _C_SLIDER_H_
#define _C_SLIDER_H_

#include "C_UIElement.h"

class C_Slider : public C_UIElement
{
	public:
		C_Slider();
		~C_Slider();
		void Init(sf::RenderWindow* window, sf::Font* font, const sf::Vector2f position);
		void Update(float& dt);

		/* Getters / Setters. */
		/* This will allow us to see if the mouse cursor is over the button. */
		inline const bool is_mouse_over() { return (getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y)); }

		inline const bool& checked() { return is_checked_; }

		inline const float& value() { return value_; }

		inline void set_checked(const bool value) { is_checked_ = value; }

		inline void set_value(const float value) { value_ = value; }

	protected:
		/* Methods. */
		void InFocusResponse();
		void OutOfFocusResponse();

	private:
		bool interactable_;
		bool is_checked_;
		bool just_changed_;
		float value_;
		sf::Sprite sprite_;
};

#endif