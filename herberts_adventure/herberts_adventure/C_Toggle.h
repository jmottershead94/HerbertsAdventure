#ifndef _C_TOGGLE_H_
#define _C_TOGGLE_H_

#include "C_UIElement.h"
#include "C_Timer.h"

class C_Toggle : public C_UIElement
{
	public:
		C_Toggle();
		~C_Toggle();
		void Init(sf::RenderWindow* window, sf::Font* font, const sf::Vector2f position);
		void Render();
		void Update(float& dt);

		/* Getters / Setters. */
		/* This will allow us to see if the mouse cursor is over the button. */
		inline const bool is_mouse_over() { return (getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y)); }

		inline const bool& checked() { return is_checked_; }

	protected:
		/* Methods. */
		void InFocusResponse();
		void OutOfFocusResponse();

	private:
		bool interactable_;
		bool is_checked_;
		bool just_changed_;
		sf::RenderWindow* window_;
		sf::Sprite sprite_;
		C_Timer delay_timer_;
};

#endif