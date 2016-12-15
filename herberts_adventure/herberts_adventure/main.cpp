/*

	Herberts Adventure
	==================
	This is a little project to just explore the components design pattern,
	and to make a small 2D game to help develop my technical skills.

	This project is currently using the full SFML library.

	Credits
	=======
	 - SFML development team (download link is in the README file).
	 - Game Programming Patterns by Robert Nystrom.

*/

/* Include header files here. */
/* Application. */
#include "C_Application.h"

/*

	Overview
	========
	This will be the main execution point for the program. The main game
	loop will be in this file.

	Returns
	=======
	int value	-	The standard value returned for the main function.

*/
int main()
{
	/* Initialising local attributes. */
	C_Application app;
	sf::Clock delta_clock;
	sf::Time dt;

	/* Setting the resolution of the application window and initialising the application. */
	app.Init(sf::Vector2i(1280, 720));

	/* While the application window is open. */
	while (app.display_window().isOpen())
	{
		/* Update the application. */
		app.Update(dt.asSeconds());

		/* Render application elements. */
		app.Render();

		/* Calculate delta time from the previous frame. */
		dt = delta_clock.restart();
	}

	/* Standard return for the main function. */
	return 0;
}