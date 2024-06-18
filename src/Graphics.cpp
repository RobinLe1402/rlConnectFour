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
					Console::SetForegroundColor(Console::Color::BrightRed);
					stream << "()";
					break;

				case Token::Player2:
					Console::SetForegroundColor(Console::Color::BrightYellow);
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

}
