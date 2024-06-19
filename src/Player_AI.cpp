#include "Player_AI.hpp"
#include "AI.hpp"

#include <iostream>



namespace rlConnectFour
{

	unsigned AIPlayer::nextMove()
	{
		std::cout << "Player " << m_iPlayerNo << " is thinking...\n";

		AI ai(m_oBoard, m_ePlayer);

		const unsigned iColumn = ai.run();

		std::cout << "Player " << m_iPlayerNo << " chose column " << (iColumn + 1) << ".\n";
		return iColumn;
	}

}
