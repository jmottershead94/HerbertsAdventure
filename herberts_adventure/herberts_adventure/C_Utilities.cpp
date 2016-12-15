#include "C_Utilities.h"

C_Utilities* utilities_instance_ = nullptr;

C_Utilities::C_Utilities()
{}

void C_Utilities::Init()
{
	if (utilities_instance_ == nullptr)
	{
		utilities_instance_ = this;
	}
}

void C_Utilities::CleanUp()
{
	if (utilities_instance_)
	{
		DELETE(utilities_instance_);
	}
}
