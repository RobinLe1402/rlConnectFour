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

		Player(Board &board);
		~Player() = default;


	protected: // variables

		Board &m_oBoard;

	};

}





#endif // ROBINLE_CONNECTFOUR_PLAYER