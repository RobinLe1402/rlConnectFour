#include "Player_Human.hpp"
#include "Graphics.hpp"

#include <iostream>
#include <string>

namespace rlConnectFour
{

	unsigned HumanPlayer::nextMove()
	{
		std::cout << *this << ", pick a column:\n";

		std::string sInput;
		while (true)
		{
			std::getline(std::cin, sInput);

			if (sInput.length() != 1 || sInput[0] < '1' || sInput[0] > '7')
			{
				std::cout << "Invalid input.\n";
				continue;
			}

			const unsigned iColumn = sInput[0] - '1';

			if (!m_oBoard.hasRoom(iColumn))
			{
				std::cout << "Column is full.\n";
				continue;
			}

			return iColumn;
		}
	}

}
