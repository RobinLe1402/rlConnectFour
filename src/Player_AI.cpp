#include "Player_AI.hpp"

#include <iostream>



namespace rlConnectFour
{

	namespace
	{

		class GameTree
		{
		public: // methods

			GameTree(const Board &oCurrentBoard, Token eSelf) :
				m_oCurrentBoard(oCurrentBoard),
				m_eSelf(eSelf),
				m_eOpponent((eSelf == Token::Player1) ? Token::Player2 : Token::Player1)
			{
				assert(eSelf == Token::Player1 || eSelf == Token::Player2);
				assert(!oCurrentBoard.isFinalState());
			}

			unsigned getBestColumn()
			{
				unsigned iResult = 0;
				float    fCurrentBest = -1;

				for (unsigned iColumn = 0; iColumn < BoardWidth; ++iColumn)
				{
					if (!m_oCurrentBoard.hasRoom(iColumn))
						continue; // no room in this column

					unsigned iEndCount = 0;
					const auto iWinCount = getWinCount(m_oCurrentBoard, iColumn, iEndCount);

					const auto fCurrent = (float)iWinCount / iEndCount;
					if (fCurrent > fCurrentBest)
					{
						fCurrentBest = fCurrent;
						iResult = iColumn;
					}
				}

				return iResult;
			}


		private: // methods

			unsigned getWinCount(const Board &board, unsigned iFirstPick, unsigned &iEndCount)
			{
				iEndCount = 0;

				Board oBoardCopy = board;
				oBoardCopy.dropToken(m_eSelf, iFirstPick);
				if (oBoardCopy.isFinalState())
				{
					++iEndCount;
					return oBoardCopy.getWinner() == m_eSelf;
				}

				unsigned iWinCount = 0;
				for (unsigned iColumnOpponent = 0; iColumnOpponent < BoardWidth; ++iColumnOpponent)
				{
					Board oBoardCopy2 = oBoardCopy;
					if (oBoardCopy2.isFinalState())
					{
						++iEndCount;
						continue;
					}

					for (unsigned iColumnSelf = 0; iColumnSelf < BoardWidth; ++iColumnSelf)
					{
						unsigned iLocalEndCount = 0;
						iWinCount += getWinCount(oBoardCopy2, iColumnSelf, iLocalEndCount);
						iEndCount += iLocalEndCount;
					}
				}

				iEndCount = 0;
			}

			
		private: // variables

			const Board &m_oCurrentBoard;
			const Token m_eSelf;
			const Token m_eOpponent;
		};

	}



	unsigned AIPlayer::nextMove()
	{
		std::cout << "Player " << m_iPlayerNo << " is thinking...\n";

		GameTree tree(m_oBoard, m_ePlayer);

		const unsigned iColumn = tree.getBestColumn();

		std::cout << "Player " << m_iPlayerNo << " chose column " << (iColumn + 1) << ".\n";
		return iColumn;
	}

}
