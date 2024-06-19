#ifndef ROBINLE_CONNECTFOUR_AI
#define ROBINLE_CONNECTFOUR_AI





#include "Board.hpp"

#include <cstdint>



namespace rlConnectFour
{

	class AI
	{
	public: // methods

		AI(const Board &board, Token eSelf);
		~AI() = default;

		unsigned run();


	private: // variables

		const Board &m_oBoard;
		const Token  m_eSelf;


	private: // static methods

		static float RateBoard(const Board &board, Token eSelf);

	};

}





#endif // ROBINLE_CONNECTFOUR_AI