#ifndef _C_OPTIONS_H_
#define _C_OPTIONS_H_

#include "C_Utilities.h"

class C_Options
{
	/* A friend class to allow access to private attributes and methods. */
	/* In this instance, meaning only the application can initialise utilities. */
	friend class C_Application;

public:
	/* Methods. */
	/* Game Options. */
	static void SetDisplayFPS(const bool value);
	static bool& DisplayFPS();

	/* Display Options. */
	static void SetVSync(const bool value);
	static bool& UseVSync();

	/* Sound Options. */
	static void SetMasterVolume(const float value);
	static float& MasterVolumeSlider();
	static float MasterVolume();

	static void SetMusicVolume(const float value);
	static float& MusicVolume();

	static void SetSFXVolume(const float value);
	static float& SFXVolume();

private:
	/* Attributes. */
	/* Game Options. */
	bool display_fps_;

	/* Display Options. */
	bool vsync_;

	/* Sound Options. */
	float master_volume_;
	float music_volume_;
	float sfx_volume_;

	/* Methods. */
	C_Options();
	void Init();
	void CleanUp();
};

#endif