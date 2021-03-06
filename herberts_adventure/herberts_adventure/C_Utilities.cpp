/* Include header files here. */
/* Application. */
#include "C_Utilities.h"

/* The static instance of utilities. */
C_Utilities* utilities_instance_ = nullptr;

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
void C_Utilities::SetText(sf::Text& text, sf::Font& font, const std::string message, const unsigned int size, const sf::Vector2f position, TextAlignment alignment)
{
	/* Setting up the text. */
	text.setFont(font);
	text.setString(message);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(size);

	if (alignment == TextAlignment::left)
	{
		text.setOrigin(text.getLocalBounds().width * 0.0f, text.getLocalBounds().height * 0.5f);
	}
	else if (alignment == TextAlignment::centre)
	{
		text.setOrigin(text.getLocalBounds().width * 0.5f, text.getLocalBounds().height * 0.5f);
	}
	else if (alignment == TextAlignment::right)
	{
		text.setOrigin(text.getLocalBounds().width * 1.0f, text.getLocalBounds().height * 0.5f);
	}	

	text.setPosition(position);
}

float C_Utilities::DegToRad(float degrees)
{
	return ((degrees * utilities_instance_->PI) / 180.0f);
}

float C_Utilities::RadToDeg(float radians)
{
	return ((radians * 180.0f) / utilities_instance_->PI);
}

float C_Utilities::Abs(const float& value)
{
	float absolute_value = value;

	if (absolute_value < 0.0f)
	{
		absolute_value *= -1.0f;
		return absolute_value;
	}

	return absolute_value;
}

float C_Utilities::Length(const sf::Vector2f& v)
{
	return std::sqrt(utilities_instance_->LengthSquared(v));
}

float C_Utilities::LengthSquared(const sf::Vector2f& v)
{
	return
	(
		v.x * v.x +
		v.y * v.y
	);
}

sf::Vector2f C_Utilities::Normalize(sf::Vector2f& v)
{
	sf::Vector2f normalized = v;

	// TODO: insert return statement here
	float magnitude = utilities_instance_->Length(normalized);

	if (magnitude)
	{
		float multiplier = 1.0f / magnitude;
		normalized.x *= multiplier;
		normalized.y *= multiplier;
	}

	return normalized;
}

float C_Utilities::DotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	return
	(
		v1.x * v2.x +
		v1.y * v2.y
	);
}

std::string C_Utilities::FloatToString(int precision, float value)
{
	/* Set the fps to 2 decimal places. */
	std::ostringstream os;
	os << std::fixed << std::setprecision(precision) << value;
	std::string string_value = os.str();
	return string_value;
}
