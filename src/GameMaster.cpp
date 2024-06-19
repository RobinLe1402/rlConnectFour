#include "GameMaster.hpp"

#include "Graphics.hpp"

#include <iostream>



namespace rlConnectFour
{

	GameMaster::GameMaster(const Options &options) :
		m_oGame(
			options.getHumanPlayerCount(),
			options.getPlayer1Starts(),
			options.getPlayer1Name(),
			options.getPlayer2Name()
		)
	{ }

	void GameMaster::run()
	{
		const auto &board = m_oGame.getBoard();

		while (!m_oGame.hasEnded())
		{
			std::cout << board;
			m_oGame.nextMove();
			std::cout << '\n';
		}

		std::cout << board;
		const auto eWinner = board.getWinner();
		
		switch (eWinner)
		{
		case Token::None:
			std::cout << "Draw!\n";
			break;

		case Token::Player1:

			std::cout << m_oGame.getPlayer(0) << " won!\n";
			break;

		case Token::Player2:
			std::cout << m_oGame.getPlayer(1) << " won!\n";
			break;
		}
	}

}
