#include "Graphics.hpp"
#include "Console.hpp"

namespace rlConnectFour
{

	std::ostream &operator<<(std::ostream &stream, const Board &board)
	{
		stream << " |1 |2 |3 |4 |5 |6 |7 |\n"
		       << " +--+--+--+--+--+--+--+\n";

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
					Console::SetForegroundColor(clPLAYER1);
					stream << "()";
					break;

				case Token::Player2:
					Console::SetForegroundColor(clPLAYER2);
					stream << "()";
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
		Console::SetForegroundColor(player.getColor());
		stream << player.getName();
		Console::ResetColors();

		return stream;
	}

}
