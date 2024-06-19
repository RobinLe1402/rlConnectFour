#include <array>
#include <iostream>

#ifdef rlWINDOWS
#define WIN32_LEAN_AND_MEAN
#define NOCOMM
#define NOMINMAX
#include <Windows.h>
#endif

#include "PlatformDependent.hpp"

#include "Console.hpp"
#include "GameMaster.hpp"
#include "Options.hpp"

#include "AI.hpp"

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

	rlConnectFour::Options opt(argc, argv);
	if (opt.getShowHelp())
	{
		opt.printHelp();
		return 0;
	}

	if (!opt.getNoBanner())
	{
		constexpr auto clFG = Console::Color::BrightWhite;
		constexpr auto clBG = Console::Color::BrightBlue;

		constexpr std::array<char[51], 3> szBANNER =
		{
			"==================================================",
			"= ROBIN LE'S  CONNECT FOUR  FOR THE COMMAND LINE =",
			"=================================================="
		};

		for (const auto sz : szBANNER)
		{
			Console::SetColors(clFG, clBG);
			std::cout << sz;
			Console::ResetColors(); std::cout << '\n';
		}
		std::cout << '\n';
	}

	rlConnectFour::GameMaster oGameMaster(opt);
	oGameMaster.run();

	// reset the console colors
	Console::ResetColors();

	return 0;
}
