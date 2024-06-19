#include "Graphics.hpp"
#include "Console.hpp"
#include "Options.hpp"

namespace rlConnectFour
{

	std::ostream &operator<<(std::ostream &stream, const Board &board)
	{
		stream << " |1 |2 |3 |4 |5 |6 |7 |\n"
		       << " +--+--+--+--+--+--+--+\n";

		const bool bNoColor = Options::NoColor();

		for (int iY = BoardHeight - 1; iY >= 0; --iY)
		{
			stream << " |";
			for (int iX = 0; iX < BoardWidth; ++iX)
			{
				switch (board.getToken(board.getIndex(iX, iY)))
				{
				case Token::None:
					stream << "  ";
					break;

				case Token::Player1:
					if (!bNoColor)
					{
						Console::SetForegroundColor(clPLAYER1);
						stream << "()";
					}
					else
						stream << "()";
					break;

				case Token::Player2:
					if (!bNoColor)
					{
						Console::SetForegroundColor(clPLAYER2);
						stream << "()";
					}
					else
						stream << "[]";
					break;
				}
				Console::ResetColors();
				stream << '|';
			}
			stream << '\n';
		}

		stream << " +--+--+--+--+--+--+--+\n";
		return stream;
	}

	std::ostream &operator<<(std::ostream &stream, const Player &player)
	{
		if (!Options::NoColor())
		{
			Console::SetForegroundColor(player.getColor());
			stream << player.getName();
			Console::ResetColors();
		}
		else
		{
			if (player.getNumber() == 1)
				stream << '(' << player.getName() << ')';
			else
				stream << '[' << player.getName() << ']';
		}

		return stream;
	}

}
