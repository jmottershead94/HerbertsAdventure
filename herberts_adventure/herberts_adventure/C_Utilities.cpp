/* Include header files here. */
/* Application. */
#include "C_Utilities.h"

/* The static instance of utilities. */
C_Utilities* utilities_instance_ = nullptr;

/*

	Overview
	========
	This method will setup any text.

	Params
	======
	sf::Text& text				-	The text that we are currently editing.

	sf::Font& font				-	The font that will be used to display this text.

	const std::string message	-	The string that will be displayed with this text.

	const unsigned int size		-	The size of the text.

	const sf::Vector2f position	-	The position of the text.

*/
void C_Utilities::SetText(sf::Text & text, sf::Font& font, const std::string message, const unsigned int size, const sf::Vector2f position)
{
	/* Setting up the text. */
	text.setFont(font);
	text.setString(message);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(size);
	text.setOrigin(text.getLocalBounds().width * 0.5f, text.getLocalBounds().height * 0.5f);
	text.setPosition(position);
}

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Utilities::C_Utilities()
{}

/*

	Overview
	========
	This method will initialise specific attribute values.

*/
void C_Utilities::Init()
{
	/* If the instance of utilities has not been assigned yet. */
	if (utilities_instance_ == nullptr)
	{
		/* Initialising the pointer attribute. */
		utilities_instance_ = new C_Utilities();

		/* Assign the instance to this class. */
		utilities_instance_ = this;
	}
}

/*

	Overview
	========
	Here we will clean up any pointer attributes in this class.

*/
void C_Utilities::CleanUp()
{
	/* Delete the utilities instance pointer. */
	//DELETE(utilities_instance_);
	if (utilities_instance_)
	{
		delete utilities_instance_;
		utilities_instance_ = nullptr;
	}
}