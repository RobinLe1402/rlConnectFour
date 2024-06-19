#include "Game.hpp"

#include "Player_AI.hpp"
#include "Player_Human.hpp"

namespace rlConnectFour
{

	namespace
	{
		
		std::string ValidString(const std::string &sCustomOption, const char *szDefault)
		{
			if (sCustomOption.empty())
				return szDefault;
			else
				return sCustomOption;
		}

	}


	Game::Game(
		unsigned iHumanPlayerCount,
		bool bPlayer1Starts,
		const std::string &sPlayer1,
		const std::string &sPlayer2
	) :
		m_cCurrentPlayer((bPlayer1Starts) ? 0 : 1)
	{
		assert(iHumanPlayerCount <= 2);

		switch (iHumanPlayerCount)
		{
		case 0:
			m_oPlayers[0] = new AIPlayer(m_oBoard, Token::Player1, ValidString(sPlayer1, "CPU 1"));
			m_oPlayers[1] = new AIPlayer(m_oBoard, Token::Player2, ValidString(sPlayer2, "CPU 2"));
			break;

		case 1:
			m_oPlayers[0] =
				new HumanPlayer(m_oBoard, Token::Player1, ValidString(sPlayer1, "Player"));
			m_oPlayers[1] =
				new AIPlayer   (m_oBoard, Token::Player2, ValidString(sPlayer2, "CPU"));
			break;

		case 2:
			m_oPlayers[0] =
				new HumanPlayer(m_oBoard, Token::Player1, ValidString(sPlayer1, "Player 1"));
			m_oPlayers[1] =
				new HumanPlayer(m_oBoard, Token::Player2, ValidString(sPlayer2, "Player 2"));
			break;
		}
	}

	bool Game::hasEnded() const
	{
		return m_oBoard.isFinalState();
	}

	void Game::nextMove()
	{
		m_oBoard.dropToken(
			(m_cCurrentPlayer == 0) ? Token::Player1 : Token::Player2,
			m_oPlayers[m_cCurrentPlayer]->nextMove()
		);
		m_cCurrentPlayer ^= 1;
	}

	const Player &Game::getPlayer(unsigned iPlayer) const
	{
		assert(iPlayer <= 2);

		return *m_oPlayers[iPlayer];
	}

}
