#include <cstdio>

#ifdef rlWINDOWS
#define WIN32_LEAN_AND_MEAN
#define NOCOMM
#define NOMINMAX
#include <Windows.h>
#endif

#include "Console.hpp"

int main(int argc, char* argv[])
{
#ifdef rlWINDOWS
	{
		// on Windows, ANSI escape sequences must be manually enabled.
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	}
#endif

	using col = Console::Color;

	Console::SetColors(col::BrightWhite, col::BrightBlue);

	std::printf(
		"==================================================\n"
		"= ROBIN LE'S  CONNECT FOUR  FOR THE COMMAND LINE =\n"
		"==================================================\n"
		"\n"
	);

	// reset the console colors
	Console::ResetColors();

	return 0;
}
