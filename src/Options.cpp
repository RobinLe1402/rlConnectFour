#include "Options.hpp"

#include <iostream>



namespace rlConnectFour
{

	Options::Options(int argc, char **argv)
	{
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
						// --ai-count
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

						// --player2-first
						else if (strcmp(szArg + 2, "player2-first") == 0)
							m_bPlayer1Starts = false;

						else
							throw std::invalid_argument(
								(std::string("unknown flag \"") + szArg + "\"").c_str()
							);
					}

					// starts with "-" => short flag
					else
					{
						size_t idx = 2;
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
			"  -h               Output this help text.\n"
			"  --ai-count x     Use x AIs. Default is 1.\n"
			"                   (x must be an integer between 0 and 2)\n"
			"                   If this value is set to 1, player 1 is the human player.\n"
			"  --player2-first  Set player 2 to start.\n"
			"                   By default, player 1 starts.\n";
	}

}
