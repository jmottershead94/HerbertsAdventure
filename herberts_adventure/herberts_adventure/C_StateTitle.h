#ifndef _C_STATETITLE_H_
#define _C_STATETITLE_H_

#include "C_State.h"

class C_StateTitle : public C_State
{
public:
	C_StateTitle(const C_State& current_state);
	~C_StateTitle();
	C_State* HandleTransitions();
	void OnEnter();
	void OnExit();
	void Render();
	void Update(float& dt);

private:
	/* Attributes. */

};

#endif