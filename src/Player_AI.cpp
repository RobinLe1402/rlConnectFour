#include "Player_AI.hpp"
#include "AI.hpp"
#include "Graphics.hpp"

#include <iostream>



namespace rlConnectFour
{

	unsigned AIPlayer::nextMove()
	{
		std::cout << *this << " is thinking...\n";

		AI ai(m_oBoard, m_ePlayer);

		const unsigned iColumn = ai.run();

		std::cout << *this << " chose column " << (iColumn + 1) << ".\n";
		return iColumn;
	}

}
