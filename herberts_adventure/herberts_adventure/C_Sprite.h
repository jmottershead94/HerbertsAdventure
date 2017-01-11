#ifndef _C_SPRITE_H_
#define _C_SPRITE_H_

#include "C_UIElement.h"

class C_Sprite : public C_UIElement
{
	public:
		C_Sprite();
		~C_Sprite();
		void Init(sf::RenderWindow* window, sf::Font* font, const sf::Vector2f position, const sf::IntRect texture_coordinates);
		void Update(float& dt);

	protected:
		/* Methods. */
		void InFocusResponse();
		void OutOfFocusResponse();

	private:
		sf::Sprite sprite_;
};

#endif