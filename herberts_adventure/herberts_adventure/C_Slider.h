#ifndef _C_SLIDER_H_
#define _C_SLIDER_H_

#include <array>
#include "C_UIElement.h"

class C_Slider : public C_UIElement
{
	public:
		C_Slider();
		~C_Slider();
		void Init(sf::RenderWindow* window, sf::Font* font, const sf::Vector2f position);
		void CheckSlider(sf::Sprite& sprite, int index);
		void Update(float& dt);

		/* Getters / Setters. */
		/* This will allow us to see if the mouse cursor is over the button. */
		inline const bool is_mouse_over(sf::Sprite& sprite) { return (sprite.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y)); }

		inline const bool& checked() { return is_checked_; }

		inline const float& value() { return value_; }

		inline std::array<sf::Sprite, 10> get_sprites() { return sprites_; }

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
		std::array<sf::Sprite, 10> sprites_;
};

#endif