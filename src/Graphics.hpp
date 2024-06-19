#ifndef ROBINLE_CONNECTFOUR_GRAPHICS
#define ROBINLE_CONNECTFOUR_GRAPHICS





#include <iostream>
#include "Board.hpp"
#include "Console.hpp"
#include "Player.hpp"



namespace rlConnectFour
{

	constexpr Console::Color clPLAYER1 = Console::Color::BrightRed;
	constexpr Console::Color clPLAYER2 = Console::Color::BrightYellow;

	std::ostream &operator<<(std::ostream &stream, const Board &board);

	std::ostream &operator<<(std::ostream &stream, const Player &player);

}





#endif // ROBINLE_CONNECTFOUR_GRAPHICS