/*

	Utilities Class
	===============

	Created:	15th December 2016
	Filter:		Header/Source Files
	Class Name:	C_Utilities
	Base Class:	N/A
	Author:		Jason Mottershead

	Purpose:	Utilities will be responsible for providing access to the most
				common methods for any class using a singleton design pattern.

*/

/* Header guard. */
#ifndef _C_UTILITIES_H_
#define _C_UTILITIES_H_

/* Macros. */
#define UNUSED(x) (void)(x)																/* Will allow a bypass for warning errors for parameters that aren't being used yet, but will definitely be used later in development. */
#define DELETE(x) if(x != nullptr) {delete x; x = nullptr;}								/* Will allow a quicker way to delete pointer attributes in one line. */
#define CLEANUPDELETE(x) if(x != nullptr) {x->CleanUp(); delete x; x = nullptr;}		/* Will allow a quicker way to clean up and delete pointer attributes in one line. */

/* Include header files here. */
/* Standard. */
#include <iomanip>
#include <iostream>
#include <cmath>

/* SFML. */
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"

/* Box2D. */
#include <Box2D\Box2D.h>

/* Application. */
#include "ObjectID.h"
#include "C_World.h"
#include "C_Debug.h"

/* Utilities is just a standard class. */
class C_Utilities
{
	/* A friend class to allow access to private attributes and methods. */
	/* In this instance, meaning only the application can initialise utilities. */
	friend class C_Application;

public:
	/* Attributes */
	enum TextAlignment
	{
		left,
		centre,
		right
	};

	/* Methods. */
	static void SetText(sf::Text& text, sf::Font& font, const std::string message, const unsigned int size, const sf::Vector2f position, TextAlignment alignment);
	static float DegToRad(float degrees);
	static float RadToDeg(float radians);
	static float Abs(const float& value);
	static float Length(const sf::Vector2f& v);
	static float LengthSquared(const sf::Vector2f& v);
	static sf::Vector2f Normalize(sf::Vector2f& v);
	static float DotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2);
	static std::string FloatToString(int precision, float value);

private:
	/* Attributes. */
	const float PI = 3.14159265358979323846f;

	/* Methods. */
	C_Utilities();
	void Init();
	void CleanUp();
};

#endif