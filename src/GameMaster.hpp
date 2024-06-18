#ifndef ROBINLE_CONNECTFOUR_GAMEMASTER
#define ROBINLE_CONNECTFOUR_GAMEMASTER





#include "Game.hpp"



namespace rlConnectFour
{

	class GameMaster
	{
	public: // methods

		GameMaster(unsigned iHumanPlayerCount, bool bPlayer1Starts);
		~GameMaster() = default;

		void run();


	private: // variables

		Game m_oGame;

	};

}





#endif // ROBINLE_CONNECTFOUR_GAMEMASTER