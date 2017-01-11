#ifndef _C_INPUT_H_
#define _C_INPUT_H_

#include "C_Utilities.h"

class C_Input
{
	friend class C_Application;

	private:
		C_Input();
		~C_Input();
		void Init();

	public:
		/* Methods. */
		static bool UpPressed();
		static bool RightPressed();
		static bool LeftPressed();
		static bool DownPressed();
		static bool APressed();
		static bool BPressed();
		static bool XPressed();
		static bool YPressed();
		static bool AcceptPressed();
		static bool CancelPressed();
		static bool JumpPressed();
		static bool StartPressed();
		static sf::Vector2f Axis(const unsigned int joystick_number);
	
};

#endif