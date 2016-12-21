#include "C_Debug.h"

C_Debug* debug_instance_ = nullptr;

C_Debug::C_Debug()
{}

C_Debug::~C_Debug()
{}

void C_Debug::Init()
{	
	if (debug_instance_ == nullptr)
	{
		debug_instance_ = new C_Debug();

		debug_instance_ = this;
	}
}

void C_Debug::PrintToConsole(std::string message)
{
	std::cout << message << std::endl;
}

//template <typename T>
void C_Debug::PrintToConsole(std::string message, float extra)
{
	std::cout << message << std::to_string(extra) << std::endl;
}