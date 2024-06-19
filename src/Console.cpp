#include "Console.hpp"

#include "Options.hpp"

#include <cstdio>



namespace
{

	constexpr char szFG_COLORS[][3] =
	{
		"30",
		"31",
		"32",
		"33",
		"34",
		"35",
		"36",
		"37",
		"90",
		"91",
		"92",
		"93",
		"94",
		"95",
		"96",
		"97"
	};

	constexpr char szBG_COLORS[][4] =
	{
		"40",
		"41",
		"42",
		"43",
		"44",
		"45",
		"46",
		"47",
		"100",
		"101",
		"102",
		"103",
		"104",
		"105",
		"106",
		"107"
	};

}



namespace Console
{

	void SetForegroundColor(Color cl)
	{
		if (rlConnectFour::Options::NoColor())
			return;

		std::printf("\033[%sm", szFG_COLORS[(size_t)cl]);
	}

	void SetBackgroundColor(Color cl)
	{
		if (rlConnectFour::Options::NoColor())
			return;

		std::printf("\033[%sm", szBG_COLORS[(size_t)cl]);
	}

	void SetColors(Color clForeground, Color clBackground)
	{
		if (rlConnectFour::Options::NoColor())
			return;

		std::printf("\033[%s;%sm",
			szFG_COLORS[(size_t)clForeground],
			szBG_COLORS[(size_t)clBackground]
		);
	}

	void ResetColors()
	{
		if (rlConnectFour::Options::NoColor())
			return;

		SetColors(Color::White, Color::Black);
	}

}
