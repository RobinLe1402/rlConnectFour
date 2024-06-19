#ifndef ROBINLE_CONNECTFOUR_GAMEMASTER
#define ROBINLE_CONNECTFOUR_GAMEMASTER





#include "Game.hpp"
#include "Options.hpp"



namespace rlConnectFour
{

	class GameMaster
	{
	public: // methods

		GameMaster(const Options &options);
		~GameMaster() = default;

		void run();


	private: // variables

		Game m_oGame;

	};

}





#endif // ROBINLE_CONNECTFOUR_GAMEMASTER