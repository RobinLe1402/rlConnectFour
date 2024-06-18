#ifndef ROBINLE_CONNECTFOUR_PLAYER
#define ROBINLE_CONNECTFOUR_PLAYER





#include "Board.hpp"



namespace rlConnectFour
{

	class Player
	{
	public: // interface methods

		virtual unsigned nextMove() = 0;



	public: // methods

		Player(const Board &board, Token player);
		virtual ~Player() = default;


	protected: // variables

		const Board &m_oBoard;
		const Token m_ePlayer;
		const unsigned m_iPlayerNo;

	};

}





#endif // ROBINLE_CONNECTFOUR_PLAYER