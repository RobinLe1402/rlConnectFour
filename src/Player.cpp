#include "Player.hpp"

namespace rlConnectFour
{

	Player::Player(const Board &board, Token player) :
		m_oBoard(board),
		m_ePlayer(player),
		m_iPlayerNo((player == Token::Player1) ? 1 : 2)
	{
		assert(player != Token::None);
	}

}
