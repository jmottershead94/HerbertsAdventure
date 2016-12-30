#include "C_Options.h"

/* The static instance of options. */
C_Options* options_instance_ = nullptr;

C_Options::C_Options()
{}

/*

	Overview
	========
	This method will initialise specific attribute values.

*/
void C_Options::Init()
{
	/* If the instance of utilities has not been assigned yet. */
	if (options_instance_ == nullptr)
	{
		/* Initialising the pointer attribute. */
		options_instance_ = new C_Options();

		/* Assign the instance to this class. */
		options_instance_ = this;
	}
}

/*

	Overview
	========
	Here we will clean up any pointer attributes in this class.

*/
void C_Options::CleanUp()
{
	/* Delete the options instance pointer. */
	//DELETE(options_instance_);
	if (options_instance_)
	{
		delete options_instance_;
		options_instance_ = nullptr;
	}
}

void C_Options::SetFPS(const bool value)
{
	if (options_instance_->display_fps_ != value)
	{
		options_instance_->display_fps_ = value;
	}
}

bool& C_Options::DisplayFPS()
{
	return options_instance_->display_fps_;
}