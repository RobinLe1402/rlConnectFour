#include <cstdio>

#ifdef rlWINDOWS
#define WIN32_LEAN_AND_MEAN
#define NOCOMM
#define NOMINMAX
#include <Windows.h>
#endif

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


	std::printf(
		"==================================================\n"
		"= ROBIN LE'S  CONNECT FOUR  FOR THE COMMAND LINE =\n"
		"==================================================\n"
		"\n"
	);

	return 0;
}
