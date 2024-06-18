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

		Player(const Board &board, unsigned playerNo);
		~Player() = default;


	protected: // variables

		const Board &m_oBoard;
		const unsigned m_iPlayerNo;

	};

}





#endif // ROBINLE_CONNECTFOUR_PLAYER