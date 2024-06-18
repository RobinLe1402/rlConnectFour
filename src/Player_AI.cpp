#include "Player_AI.hpp"

#include <iostream>



namespace rlConnectFour
{

	namespace
	{

		class GameTree
		{
		public: // methods

			GameTree(const Board &oCurrentBoard, Token eSelf, unsigned iMaxDepth) :
				m_oCurrentBoard(oCurrentBoard),
				m_eSelf(eSelf),
				m_eOpponent((eSelf == Token::Player1) ? Token::Player2 : Token::Player1),
				m_iMaxDepth(iMaxDepth)
			{
				assert(eSelf == Token::Player1 || eSelf == Token::Player2);
				assert(!oCurrentBoard.isFinalState());
				assert(iMaxDepth > 0);
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
					const auto iWinCount = getWinCount(m_oCurrentBoard, iColumn, iEndCount, 1);

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

			unsigned getWinCount(
				const Board &board,
				unsigned iFirstPick,
				unsigned &iEndCount,
				unsigned iCurrentDepth
			)
			{
				iEndCount = 0;

				Board oBoardCopy = board;
				oBoardCopy.dropToken(m_eSelf, iFirstPick);
				if (oBoardCopy.isFinalState())
				{
					++iEndCount;
					return oBoardCopy.getWinner() == m_eSelf;
				}

				if (iCurrentDepth == m_iMaxDepth)
					return 0;

				unsigned iWinCount = 0;
				for (unsigned iColumnOpponent = 0; iColumnOpponent < BoardWidth; ++iColumnOpponent)
				{
					if (!oBoardCopy.hasRoom(iColumnOpponent))
						continue;

					Board oBoardCopy2 = oBoardCopy;
					if (oBoardCopy2.isFinalState())
					{
						++iEndCount;
						continue;
					}

					for (unsigned iColumnSelf = 0; iColumnSelf < BoardWidth; ++iColumnSelf)
					{
						if (!oBoardCopy2.hasRoom(iColumnSelf))
							continue;

						unsigned iLocalEndCount = 0;
						iWinCount += getWinCount(oBoardCopy2, iColumnSelf, iLocalEndCount,
							iCurrentDepth + 1
						);
						iEndCount += iLocalEndCount;
					}
				}

				return iWinCount;
			}

			
		private: // variables

			const Board &m_oCurrentBoard;
			const Token m_eSelf;
			const Token m_eOpponent;
			const unsigned m_iMaxDepth;
		};

	}



	unsigned AIPlayer::nextMove()
	{
		std::cout << "Player " << m_iPlayerNo << " is thinking...\n";

		GameTree tree(m_oBoard, m_ePlayer, 5);

		const unsigned iColumn = tree.getBestColumn();

		std::cout << "Player " << m_iPlayerNo << " chose column " << (iColumn + 1) << ".\n";
		return iColumn;
	}

}
