#include "C_Camera.h"

C_Camera::C_Camera()
{}

C_Camera::~C_Camera()
{}

void C_Camera::Init(sf::RenderWindow* window, sf::FloatRect viewport)
{
	/* Initialising attributes. */
	window_ = window;
	viewport_ = viewport;
	reset(viewport_);
	setCenter(sf::Vector2f(viewport_.left + (viewport_.width * 0.5f), viewport_.top + (viewport_.height * 0.5f)));
}

void C_Camera::Update(sf::Vector2f position, float& dt)
{
	UNUSED(dt);
	setCenter(position);
}