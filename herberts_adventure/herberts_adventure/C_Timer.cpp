/* Include header files here. */
/* Application. */
#include "C_Timer.h"

/*

	Overview
	========
	This method will initialise default values for our attributes.

*/
C_Timer::C_Timer() :
	desired_time_(0.0f)
{}

/*

	Overview
	========
	This method will be called when the object is destroyed.

*/
C_Timer::~C_Timer()
{}

/*

	Overview
	========
	This method will provide a way to check if the timer has been on for the
	correct amount of time.

	Returns
	=======
	boolean true/false	-	If the timer is up or not.

*/
bool C_Timer::Finished()
{
	/* If the current time is greater than or equal to the desired time. */
	if ((clock_.getElapsedTime().asSeconds() - start_time_.asSeconds()) >= desired_time_)
	{
		/* The desired time has passed. */
		return true;
	}

	/* Otherwise, the desired time has not yet passed. */
	return false;
}