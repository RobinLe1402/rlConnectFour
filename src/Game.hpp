#ifndef ROBINLE_CONNECTFOUR_GAME
#define ROBINLE_CONNECTFOUR_GAME





#include "Player.hpp"



namespace rlConnectFour
{

	class Game
	{
	public: // methods

		Game(
			unsigned iHumanPlayerCount,
			bool bPlayer1Starts,
			const std::string &sPlayer1,
			const std::string &sPlayer2
		);
		~Game() = default;

		bool hasEnded() const;
		void nextMove();

		const Board &getBoard() const { return m_oBoard; }
		const Player &getPlayer(unsigned iPlayer) const;


	private: // variables

		char    m_cCurrentPlayer;
		Board   m_oBoard      = {};
		Player *m_oPlayers[2] = {};

	};

}





#endif // ROBINLE_CONNECTFOUR_GAME