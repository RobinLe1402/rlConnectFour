#include "GameMaster.hpp"

#include "Graphics.hpp"

#include <iostream>



namespace rlConnectFour
{

	GameMaster::GameMaster(unsigned iHumanPlayerCount, bool bPlayer1Starts) :
		m_oGame(iHumanPlayerCount, bPlayer1Starts)
	{ }

	void GameMaster::run()
	{
		const auto &board = m_oGame.getBoard();

		while (!m_oGame.hasEnded())
		{
			std::cout << board;
			m_oGame.nextMove();
		}

		std::cout << board;
		const auto eWinner = board.getWinner();
		
		switch (eWinner)
		{
		case Token::None:
			std::cout << "Draw!\n";
			break;

		case Token::Player1:
			std::cout << "Player 1 won!\n";
			break;

		case Token::Player2:
			std::cout << "Player 2 won!\n";
			break;
		}
	}

}
