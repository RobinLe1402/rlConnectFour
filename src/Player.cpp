#include "Player.hpp"
#include "Graphics.hpp"


namespace rlConnectFour
{

	Player::Player(const Board &board, Token player) :
		m_oBoard(board),
		m_ePlayer(player),
		m_iPlayerNo((player == Token::Player1) ? 1 : 2),
		m_eColor(m_iPlayerNo == 1 ? clPLAYER1 : clPLAYER2)
	{
		assert(player != Token::None);
	}

	std::string Player::getName() const
	{
		return "Player " + std::to_string(m_iPlayerNo);
	}

}
