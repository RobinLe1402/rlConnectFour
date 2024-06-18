#ifndef ROBINLE_CONNECTFOUR_PLAYER_HUMAN
#define ROBINLE_CONNECTFOUR_PLAYER_HUMAN





#include "Player.hpp"

namespace rlConnectFour
{

	class HumanPlayer : public Player
	{
	public: // methods

		using Player::Player;
		~HumanPlayer() = default;

		unsigned nextMove() override;

	};

}





#endif // ROBINLE_CONNECTFOUR_PLAYER_HUMAN