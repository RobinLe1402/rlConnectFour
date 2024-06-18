#ifndef ROBINLE_CONNECTFOUR_BOARD
#define ROBINLE_CONNECTFOUR_BOARD





#include <cassert>



namespace rlConnectFour
{

	enum class Token : unsigned char
	{
		None,
		Player1,
		Player2
	};



	constexpr size_t BoardWidth  = 7;
	constexpr size_t BoardHeight = 6;
	constexpr size_t BoardSize   = BoardWidth * BoardHeight;


	class Board
	{
	public: // methods

		bool isFinalState() const;
		bool hasRoom(unsigned iColumn) const;

		Token getToken(unsigned idx) const
		{
			assert(idx < BoardSize);
			return m_eTokens[idx];
		}
		
		unsigned getIndex(unsigned iColumn, unsigned iRowFromBottom) const;

		Token getWinner() const { return m_eWinner; }


		void dropToken(Token ePlayer, unsigned iColumn);


	private: // methods

		void checkWinner(size_t iLastDropped);


	private: // variables

		// the tokens array is indexed column by column, bottom to top:
		// 
		// |05|11|..|41|
		// |..|..|..|..|
		// |02|08|..|38|
		// |01|07|..|37|
		// |00|06|..|36|
		Token  m_eTokens    [BoardSize ] = {};
		size_t m_iTokenCount[BoardWidth] = {};
		Token  m_eWinner                 = Token::None;

	};

}





#endif // ROBINLE_CONNECTFOUR_BOARD