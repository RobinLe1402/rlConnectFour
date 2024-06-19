#include "Player.hpp"
#include "Graphics.hpp"


namespace rlConnectFour
{

	Player::Player(const Board &board, Token player, const char *szName) :
		m_oBoard(board),
		m_ePlayer(player),
		m_iPlayerNo((player == Token::Player1) ? 1 : 2),
		m_eColor(m_iPlayerNo == 1 ? clPLAYER1 : clPLAYER2),
		m_sName(szName)
	{
		assert(player != Token::None);
		assert(szName && szName[0]);
	}

	const std::string &Player::getName() const
	{
		return m_sName;
	}

}
