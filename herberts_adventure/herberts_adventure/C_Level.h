#ifndef _C_LEVEL_H_
#define _C_LEVEL_H_

#include "C_Utilities.h"
#include "C_GameObject.h"

class C_Level
{
public:
	/* Methods. */
	C_Level();
	void Init(sf::RenderWindow* window);
	void CleanUp();
	void Render();
	void Update(float& dt);

private:
	sf::RenderWindow* window_;	/* Points to the main render window in the application class. */
	C_GameObject test_;			/* Testing game objects out. */
};

#endif