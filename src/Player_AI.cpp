#include "Player_AI.hpp"

namespace rlConnectFour
{

	unsigned AIPlayer::nextMove()
	{
		// TODO: proper AI
		for (unsigned i = 0; i < BoardWidth; ++i)
		{
			if (m_oBoard.hasRoom(i))
				return i;
		}
	}

}
