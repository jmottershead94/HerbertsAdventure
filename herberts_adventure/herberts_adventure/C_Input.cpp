#include "C_Input.h"

C_Input* input_instance_ = nullptr;

C_Input::C_Input()
{}

C_Input::~C_Input()
{}

/*

	Overview
	========
	This method will initialise specific attribute values.

*/
void C_Input::Init()
{
	/* If the instance of utilities has not been assigned yet. */
	if (input_instance_ == nullptr)
	{
		/* Initialising the pointer attribute. */
		input_instance_ = new C_Input();

		/* Assign the instance to this class. */
		input_instance_ = this;
	}
}

bool C_Input::UpPressed()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || input_instance_->Axis(0).y > -15.0f);
}

bool C_Input::RightPressed()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || input_instance_->Axis(0).x > 15.0f);
}

bool C_Input::LeftPressed()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || input_instance_->Axis(0).x < -15.0f);
}

bool C_Input::DownPressed()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || input_instance_->Axis(0).y < 15.0f);
}

bool C_Input::APressed()
{
	return sf::Joystick::isButtonPressed(0, 0);
}

bool C_Input::BPressed()
{
	return sf::Joystick::isButtonPressed(0, 1);
}

bool C_Input::XPressed()
{
	return sf::Joystick::isButtonPressed(0, 8);
}

bool C_Input::YPressed()
{
	return sf::Joystick::isButtonPressed(0, 3);
}

bool C_Input::AcceptPressed()
{
	return (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Joystick::isButtonPressed(0, 0));
}

bool C_Input::CancelPressed()
{
	return (sf::Joystick::isButtonPressed(0, 1));
}

bool C_Input::JumpPressed()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Joystick::isButtonPressed(0, 0));
}

bool C_Input::StartPressed()
{
	return sf::Joystick::isButtonPressed(0, 7);
}

sf::Vector2f C_Input::Axis(const unsigned int joystick_number)
{
	return sf::Vector2f(sf::Joystick::getAxisPosition(joystick_number, sf::Joystick::X), sf::Joystick::getAxisPosition(joystick_number, sf::Joystick::Y));
}

/*

	Xbox 360
	========

	A - 0
	B - 1
	X - ?
	Y - 4
	RB - 5
	LB - 6
	START - 7


*/