#ifndef ROBINLE_CONNECTFOUR_GAME
#define ROBINLE_CONNECTFOUR_GAME





#include "Player.hpp"



namespace rlConnectFour
{

	class Game
	{
	public: // methods

		Game(unsigned iHumanPlayerCount = 1, bool bPlayer1Starts = true);
		~Game() = default;

		bool hasEnded() const;
		void nextMove();


	private: // variables

		char    m_cCurrentPlayer;
		Board   m_oBoard      = {};
		Player *m_oPlayers[2] = {};

	};

}





#endif // ROBINLE_CONNECTFOUR_GAME