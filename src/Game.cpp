#include "Game.hpp"

#include "Player_AI.hpp"
#include "Player_Human.hpp"

namespace rlConnectFour
{

	Game::Game(unsigned iHumanPlayerCount, bool bPlayer1Starts) :
		m_cCurrentPlayer((bPlayer1Starts) ? 0 : 1)
	{
		assert(iHumanPlayerCount <= 2);

		switch (iHumanPlayerCount)
		{
		case 0:
			m_oPlayers[0] = new AIPlayer(m_oBoard, 1);
			m_oPlayers[1] = new AIPlayer(m_oBoard, 2);
			break;

		case 1:
			m_oPlayers[0] = new HumanPlayer(m_oBoard, 1);
			m_oPlayers[1] = new AIPlayer   (m_oBoard, 2);
			break;

		case 2:
			m_oPlayers[0] = new HumanPlayer(m_oBoard, 1);
			m_oPlayers[1] = new HumanPlayer(m_oBoard, 2);
			break;
		}
	}

	bool Game::hasEnded() const
	{
		return m_oBoard.getWinner() != Token::None;
	}

	void Game::nextMove()
	{
		m_oBoard.dropToken(
			(m_cCurrentPlayer == 0) ? Token::Player1 : Token::Player2,
			m_oPlayers[m_cCurrentPlayer]->nextMove()
		);
		m_cCurrentPlayer ^= 1;
	}

}