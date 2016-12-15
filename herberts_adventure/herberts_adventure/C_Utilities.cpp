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