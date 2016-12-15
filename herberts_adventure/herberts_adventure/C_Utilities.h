#ifndef _C_UTILITIES_H_
#define _C_UTILITIES_H_

/* Macros. */
#define UNUSED(x) (void)(x)

class C_Utilities
{
	/* A friend class to allow access to private attributes and methods. */
	/* In this instance, meaning only the application can initialise utilities. */
	friend class C_Application;

private:
	C_Utilities();
	void CleanUp();
};

#endif