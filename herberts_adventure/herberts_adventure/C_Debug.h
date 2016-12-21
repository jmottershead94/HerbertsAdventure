#ifndef _C_DEBUG_H_
#define _C_DEBUG_H_

#include <iostream>
#include <sstream>

class C_Debug
{
	/* Friend class so that only the application can initialise debug classes. */
	friend class C_Application;

public:
	/* Methods. */
	static void PrintToConsole(std::string message);

	static void PrintToConsole(std::string message, float extra);// { std::cout << message << extra << std::endl; }
	
private:
	C_Debug();
	~C_Debug();
	void Init();

};

#endif