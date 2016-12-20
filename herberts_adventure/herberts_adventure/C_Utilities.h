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
/* SFML. */
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"

/* Box2D. */
#include <Box2D\Common\b2Math.h>

/* Utilities is just a standard class. */
class C_Utilities
{
	/* A friend class to allow access to private attributes and methods. */
	/* In this instance, meaning only the application can initialise utilities. */
	friend class C_Application;

public:
	/* Methods. */
	static void SetText(sf::Text& text, sf::Font& font, const std::string message, const unsigned int size, const sf::Vector2f position);

private:
	/* Methods. */
	C_Utilities();
	void Init();
	void CleanUp();
};

#endif