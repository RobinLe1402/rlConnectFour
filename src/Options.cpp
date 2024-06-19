#include "Options.hpp"

#include <cassert>
#include <cstring>
#include <iostream>



namespace rlConnectFour
{

	Options *Options::s_pInstance = nullptr;



	Options::Options(int argc, char **argv)
	{
		assert(s_pInstance == nullptr);
		s_pInstance = this;

		try
		{
			for (unsigned iArg = 1; iArg < (unsigned)argc; ++iArg)
			{
				const auto szArg = argv[iArg];

				if (szArg[0] == '-')
				{
					// starts with "--" => long flag
					if (szArg[1] == '-')
					{
						// --ai-count <count>
						if (strcmp(szArg + 2, "ai-count") == 0)
						{
							if (iArg + 1 == argc)
								throw std::invalid_argument("Expected value after --ai-count");

							const auto szAICount = argv[iArg + 1];
							if (szAICount[0] < '0' || szAICount[0] > '2' || szAICount[1])
								throw std::invalid_argument("Invalid value after --ai-count");

							m_iHumanPlayerCount = 2 - (szAICount[0] - '0');

							++iArg; // skip value in validation
						}

						// --no-banner
						else if (strcmp(szArg + 2, "no-banner") == 0)
							m_bNoBanner = true;

						// --no-color
						else if (strcmp(szArg + 2, "no-color") == 0)
							m_bNoColor = true;

						// --player1 <name>
						else if (strcmp(szArg + 2, "player1") == 0)
						{
							if (iArg + 1 == argc)
								throw std::invalid_argument("Expected value after --player1");

							m_sPlayerNames[0] = argv[iArg + 1];

							++iArg; // skip value in validation
						}

						// --player2 <name>
						else if (strcmp(szArg + 2, "player2") == 0)
						{
							if (iArg + 1 == argc)
								throw std::invalid_argument("Expected value after --player2");

							m_sPlayerNames[1] = argv[iArg + 1];

							++iArg; // skip value in validation
						}

						// --player2-first
						else if (strcmp(szArg + 2, "player2-first") == 0)
							m_bPlayer1Starts = false;

						// --help
						else if (strcmp(szArg + 2, "help") == 0)
							m_bShowHelp = true;

						else
							throw std::invalid_argument(
								(std::string("unknown flag \"") + szArg + "\"").c_str()
							);
					}

					// starts with "-" => short flag
					else
					{
						size_t idx = 1;
						char c = szArg[idx];
						while (c)
						{
							switch (c)
							{
							case 'h': // -h => show help
								m_bShowHelp = true;
								break;

							default:
								std::cerr << "Invalid flag \"" << c << "\".\n";
								exit(EXIT_FAILURE);
							}

							c = szArg[++idx];
						}
					}
				}
			}
		}
		catch (const std::invalid_argument &e)
		{
			std::cerr << "Invalid arguments: " << e.what() << '\n';
			exit(EXIT_FAILURE);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error while checking arguments: " << e.what() << '\n';
			exit(EXIT_FAILURE);
		}
	}

	void Options::printHelp() const
	{
		std::cout <<
			"OPTIONS:\n"
			"  -h, --help        Output this help text.\n"
			"  --ai-count <x>    Use <x> AIs. Default is 1.\n"
			"                    (<x> must be an integer between 0 and 2)\n"
			"                    If this value is set to 1, player 1 is the human player.\n"
			"  --no-banner       Hide the banner.\n"
			"  --no-color        Disable ANSI escape sequences for colors.\n"
			"  --player1 <name>  Set the name of player 1 to <name>.\n"
			"  --player2 <name>  Set the name of player 2 to <name>.\n"
			"  --player2-first   Set player 2 to start.\n"
			"                    By default, player 1 starts.\n";
	}

}
