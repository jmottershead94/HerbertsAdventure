#ifndef _C_OPTIONS_H_
#define _C_OPTIONS_H_

#include "C_Utilities.h"

class C_Options
{
	/* A friend class to allow access to private attributes and methods. */
	/* In this instance, meaning only the application can initialise utilities. */
	friend class C_Application;

public:
	/* Methods. */
	static void SetDisplayFPS(const bool value);
	static void SetVSync(const bool value);

	static bool& DisplayFPS();
	static bool& UseVSync();

private:
	/* Attributes. */
	bool display_fps_;
	bool vsync_;

	/* Methods. */
	C_Options();
	void Init();
	void CleanUp();
};

#endif