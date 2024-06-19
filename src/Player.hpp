#ifndef ROBINLE_CONNECTFOUR_PLAYER
#define ROBINLE_CONNECTFOUR_PLAYER





#include "Board.hpp"
#include "Console.hpp"

#include <string>



namespace rlConnectFour
{

	class Player
	{
	public: // interface methods

		virtual unsigned nextMove() = 0;



	public: // methods

		Player(const Board &board, Token player, const std::string &sName);
		virtual ~Player() = default;

		const std::string &getName() const;
		Console::Color getColor() const { return m_eColor; }
		unsigned getNumber() const { return m_iPlayerNo; }


	protected: // variables

		const Board &m_oBoard;
		const Token m_ePlayer;
		const unsigned m_iPlayerNo;
		const Console::Color m_eColor;


	private: // variables
		
		const std::string m_sName;

	};

}





#endif // ROBINLE_CONNECTFOUR_PLAYER