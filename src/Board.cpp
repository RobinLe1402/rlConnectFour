#include "Board.hpp"



namespace rlConnectFour
{

	bool Board::isFinalState() const
	{
		return m_eWinner != Token::None ||
		(
			m_iTokenCount[0] == BoardHeight &&
			m_iTokenCount[1] == BoardHeight &&
			m_iTokenCount[2] == BoardHeight &&
			m_iTokenCount[3] == BoardHeight &&
			m_iTokenCount[4] == BoardHeight &&
			m_iTokenCount[5] == BoardHeight &&
			m_iTokenCount[6] == BoardHeight
		);
	}

	bool Board::hasRoom(unsigned iColumn) const
	{
		assert(iColumn < BoardWidth);

		return m_iTokenCount[iColumn] < BoardHeight;
	}

	unsigned Board::getTokenCount(unsigned iColumn) const
	{
		assert(iColumn < BoardWidth);

		return (unsigned)m_iTokenCount[iColumn];
	}

	unsigned Board::getIndex(unsigned iColumn, unsigned iRowFromBottom) const
	{
		assert(iColumn        < BoardWidth);
		assert(iRowFromBottom < BoardHeight);

		return iColumn * BoardHeight + iRowFromBottom;
	}

	void Board::dropToken(Token ePlayer, unsigned iColumn)
	{
		assert(iColumn < BoardWidth);
		assert(m_iTokenCount[iColumn] < BoardHeight);
		assert(ePlayer != Token::None);
		assert(m_eWinner == Token::None);

		const auto idx = iColumn * BoardHeight + m_iTokenCount[iColumn];
		m_eTokens[idx] = ePlayer;
		++m_iTokenCount[iColumn];

		checkWinner(idx);
	}

	void Board::checkWinner(size_t iLastDropped)
	{
		assert(iLastDropped < BoardSize);
		assert(m_eTokens[iLastDropped] != Token::None);

		const Token    eDropped = m_eTokens[iLastDropped];
		const unsigned iDropCol = unsigned(iLastDropped / BoardHeight);
		const unsigned iDropRow = unsigned(iLastDropped % BoardHeight);


		// 1. check downwards
		if (iDropRow >= 3)
		{
			if (
				m_eTokens[iLastDropped - 1] == eDropped &&
				m_eTokens[iLastDropped - 2] == eDropped &&
				m_eTokens[iLastDropped - 3] == eDropped
			)
			{
				m_eWinner = eDropped;
				return;
			}
		}



		// 2. check horizontal
		unsigned iTokenCount;
		size_t   idx;
		int      iCol;
		int      iRow;
		{
			iTokenCount = 1;

			// <--X
			for (
				idx = iLastDropped - BoardHeight, iCol = iDropCol - 1;
				iCol >= 0 && m_eTokens[idx] == eDropped;
				--iCol, idx -= BoardHeight
			)
			{
				++iTokenCount;
			}

			// X-->
			for (
				idx = iLastDropped + BoardHeight, iCol = iDropCol + 1;
				iCol < BoardWidth && m_eTokens[idx] == eDropped;
				++iCol, idx += BoardHeight
			)
			{
				++iTokenCount;
			}


			if (iTokenCount >= 4)
			{
				m_eWinner = eDropped;
				return;
			}
		}


		// 3. check diagnoal 1 (bottom left to top right)
		{
			iTokenCount = 1;

			// down left
			for (
				idx = iLastDropped - BoardHeight - 1,
					iCol = iDropCol - 1,
					iRow = iDropRow - 1;
				iCol >= 0 && iRow >= 0 && m_eTokens[idx] == eDropped;
				--iCol, --iRow, idx -= BoardHeight + 1
			)
			{
				++iTokenCount;
			}

			// up right
			for (
				idx = iLastDropped + BoardHeight + 1,
					iCol = iDropCol + 1,
					iRow = iDropRow + 1;
				iCol < BoardWidth && iRow < BoardHeight && m_eTokens[idx] == eDropped;
				++iCol, ++iRow, idx += BoardHeight + 1
			)
			{
				++iTokenCount;
			}


			if (iTokenCount >= 4)
			{
				m_eWinner = eDropped;
				return;
			}
		}


		// 4. check diagnoal 2 (top left to bottom right)
		{
			iTokenCount = 1;

			// up left
			for (
				idx = iLastDropped - BoardHeight + 1,
					iCol = iDropCol - 1,
					iRow = iDropRow + 1;
				iCol >= 0 && iRow < BoardHeight && m_eTokens[idx] == eDropped;
				--iCol, ++iRow, idx -= (BoardHeight - 1)
			)
			{
				++iTokenCount;
			}

			// down right
			for (
				idx = iLastDropped + BoardHeight - 1,
					iCol = iDropCol + 1,
					iRow = iDropRow - 1;
				iCol < BoardWidth && iRow >= 0 && m_eTokens[idx] == eDropped;
				++iCol, --iRow, idx += BoardHeight - 1
			)
			{
				++iTokenCount;
			}


			if (iTokenCount >= 4)
			{
				m_eWinner = eDropped;
				return;
			}
		}

	}

}
