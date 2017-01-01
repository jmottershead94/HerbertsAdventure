#ifndef _C_CAMERA_H_
#define _C_CAMERA_H_

#include "C_Utilities.h"

class C_Camera : public sf::View
{
	public:
		/* Methods. */
		C_Camera();
		~C_Camera();
		void Init(sf::RenderWindow* window, sf::FloatRect viewport);
		void Update(sf::Vector2f position, float& dt);

		inline sf::FloatRect& viewport() { return viewport_; }

	private:
		/* Attributes. */
		sf::RenderWindow* window_;
		sf::Vector2f position_;
		sf::FloatRect viewport_;
};

#endif