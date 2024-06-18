#ifndef ROBINLE_CONNECTFOUR_PLAYER_AI
#define ROBINLE_CONNECTFOUR_PLAYER_AI





#include "Player.hpp"

namespace rlConnectFour
{

	class AIPlayer : public Player
	{
	public: // methods

		using Player::Player;
		~AIPlayer() = default;

		unsigned nextMove() override;

	};

}





#endif // ROBINLE_CONNECTFOUR_PLAYER_AI