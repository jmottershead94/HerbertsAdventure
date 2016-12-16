
/* Header guard. */
#ifndef _C_UIELEMENT_H_
#define _C_UIELEMENT_H_

/* Include header files here. */
/* Application. */
#include "C_GameObject.h"

/* UI element IS A game object, therefore inherits from it. */
class C_UIElement : public C_GameObject
{
public:
	/* Methods. */
	/* Virtual. */
	/* Pure virtual because all inheriting UI elements must implement these methods. */
	virtual void InFocusResponse() = 0;
	virtual void OutOfFocusResponse() = 0;

	C_UIElement();

	/* Getters/Setters. */
	/* This will let us know if this UI element is in focus or not. */
	inline const bool& is_in_focus() { return in_focus_; }

	/* This will allow us to set the current focus value of the element. */
	inline void set_focus(const bool value) { in_focus_ = value; }

private:
	/* Attributes. */
	bool in_focus_;		/* If the UI element is in focus or not. */
};

#endif