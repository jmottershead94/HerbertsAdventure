/*

	Timer Class
	===========

	Created:	15th December 2016
	Filter:		Header/Source Files
	Class Name:	C_Timer
	Base Class:	N/A
	Author:		Jason Mottershead

	Purpose:	The timer will be used to time events (such as the splash screen),
				for a variable amount of time.

*/

/* Header guard. */
#ifndef _C_TIMER_H_
#define _C_TIMER_H_

/* Include header files here. */
/* Application. */
#include "C_Utilities.h"

/* Timer is just a standard class. */
class C_Timer
{
	public:
		/* Methods. */
		C_Timer();
		~C_Timer();
		bool Finished();

		/* Setters. */
		/* This will allow the overall time for the timer to be set. */
		inline void set_time(const float value) { desired_time_ = value; }

		/* This will allow the clock to set the current start time. */
		inline void start() { start_time_ = clock_.getElapsedTime(); }

	private: 
		/* Attributes. */
		sf::Clock clock_;			/* Used to access the current time. */
		sf::Time start_time_;		/* Used to access the start time. */
		float desired_time_;		/* Used to check if the timer has been used for the desired amount of time. */
};

#endif