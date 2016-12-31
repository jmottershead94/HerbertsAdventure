#include "C_Options.h"

/* The static instance of options. */
C_Options* options_instance_ = nullptr;

C_Options::C_Options() :
	display_fps_(true),
	vsync_(true),
	lock_fps_(true),
	master_volume_(100.0f),
	music_volume_(10.0f),
	sfx_volume_(10.0f)
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

/* Game Options. */
void C_Options::SetDisplayFPS(const bool value)
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

/* Display Options. */
void C_Options::SetVSync(const bool value)
{
	if (options_instance_->vsync_ != value)
	{
		options_instance_->vsync_ = value;
	}
}

void C_Options::SetLockedFPS(const bool value)
{
	options_instance_->lock_fps_ = value;
}

bool& C_Options::UseVSync()
{
	return options_instance_->vsync_;
}

bool& C_Options::LockFPS()
{
	return (options_instance_->lock_fps_);
}

/* Sound Options. */
void C_Options::SetMasterVolume(const float value)
{
	options_instance_->master_volume_ = value;
}

float & C_Options::MasterVolumeSlider()
{
	return options_instance_->master_volume_;
}

float C_Options::MasterVolume()
{
	float master_volume = options_instance_->master_volume_ * 0.01f;
	return master_volume;
}

void C_Options::SetMusicVolume(const float value)
{
	options_instance_->music_volume_ = value;
}

float& C_Options::MusicVolume()
{
	return options_instance_->music_volume_;
}

void C_Options::SetSFXVolume(const float value)
{
	options_instance_->sfx_volume_ = value;
}

float& C_Options::SFXVolume()
{
	return options_instance_->sfx_volume_;
}