#include "Player_AI.hpp"

#include <iostream>

namespace rlConnectFour
{

	unsigned AIPlayer::nextMove()
	{
		std::cout << "Player " << m_iPlayerNo << " is thinking...\n";

		unsigned iColumn;

		// TODO: proper AI
		for (unsigned i = 0; i < BoardWidth; ++i)
		{
			if (m_oBoard.hasRoom(i))
			{
				iColumn = i;
				break; // for
			}
		}

		std::cout << "Player " << m_iPlayerNo << " chose column " << (iColumn + 1) << ".\n";
		return iColumn;
	}

}
