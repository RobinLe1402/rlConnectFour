#include "AI.hpp"

#include <array>
#include <limits>
#include <vector>


namespace rlConnectFour
{

	namespace
	{

		const std::array<std::vector<uint8_t>, 25> oStripes =
		{
			// vertical:
			// 0 1 2 3 4 5 6
			// 0 1 2 3 4 5 6
			// 0 1 2 3 4 5 6
			// 0 1 2 3 4 5 6
			// 0 1 2 3 4 5 6
			// 0 1 2 3 4 5 6
			std::vector<uint8_t>({  0,  1,  2,  3,  4,  5 }),
			std::vector<uint8_t>({  6,  7,  8,  9, 10, 11 }),
			std::vector<uint8_t>({ 12, 13, 14, 15, 16, 17 }),
			std::vector<uint8_t>({ 18, 19, 20, 21, 22, 23 }),
			std::vector<uint8_t>({ 24, 25, 26, 27, 28, 29 }),
			std::vector<uint8_t>({ 30, 31, 32, 33, 34, 35 }),
			std::vector<uint8_t>({ 36, 37, 38, 39, 40, 41 }),

			// horizontal:
			// 0 0 0 0 0 0 0
			// 1 1 1 1 1 1 1
			// 2 2 2 2 2 2 2
			// 3 3 3 3 3 3 3
			// 4 4 4 4 4 4 4
			// 5 5 5 5 5 5 5
			std::vector<uint8_t>({ 5, 11, 17, 23, 29, 35, 41 }),
			std::vector<uint8_t>({ 4, 10, 16, 22, 28, 34, 40 }),
			std::vector<uint8_t>({ 3,  9, 15, 21, 27, 33, 39 }),
			std::vector<uint8_t>({ 2,  8, 14, 20, 26, 32, 38 }),
			std::vector<uint8_t>({ 1,  7, 13, 19, 25, 31, 37 }),
			std::vector<uint8_t>({ 0,  6, 12, 18, 24, 30, 36 }),

			// diagonal 1:
			// - - - 0 1 2 3
			// - - 0 1 2 3 4
			// - 0 1 2 3 4 5
			// 0 1 2 3 4 5 -
			// 1 2 3 4 5 - -
			// 2 3 4 5 - - -
			std::vector<uint8_t>({  2,  9, 16, 23 }),
			std::vector<uint8_t>({  1,  8, 15, 22, 29 }),
			std::vector<uint8_t>({  0,  7, 14, 21, 28, 35 }),
				std::vector<uint8_t>({  6, 13, 20, 27, 34, 41 }),
					std::vector<uint8_t>({ 12, 19, 26, 33, 40 }),
						std::vector<uint8_t>({ 18, 25, 32, 39 }),

			// diagonal 2:
			// 2 3 4 5 - - -
			// 1 2 3 4 5 - -
			// 0 1 2 3 4 5 -
			// - 0 1 2 3 4 5
			// - - 0 1 2 3 4
			// - - - 0 1 2 3
			std::vector<uint8_t>({  3,  8, 13, 18 }),
			std::vector<uint8_t>({  4,  9, 14, 19, 24 }),
			std::vector<uint8_t>({  5, 10, 15, 20, 25, 30 }),
				std::vector<uint8_t>({ 11, 16, 21, 26, 31, 36 }),
					std::vector<uint8_t>({ 17, 22, 27, 32, 37 }),
						std::vector<uint8_t>({ 23, 28, 33, 38 })
		};

		struct FieldInfo
		{
			Token eType;
			int8_t iHeightDiff;
		};

		using DataStripe = std::vector<FieldInfo>;

		using DataStripes = std::array<DataStripe, oStripes.size()>;



		DataStripes GetDataStripes(const Board &board)
		{
			DataStripes oResult = {};

			for (unsigned iStripe = 0; iStripe < oStripes.size(); ++iStripe)
			{
				auto &dest = oResult[iStripe];
				dest.reserve(7);
				for (const auto &idx : oStripes[iStripe])
				{
					const auto iCol = idx / BoardHeight;
					const auto iRow = idx % BoardHeight;

					FieldInfo fi{};
					fi.eType       = board.getToken(idx);
					fi.iHeightDiff = int8_t(iRow) + 1 - (int8_t)board.getTokenCount((unsigned)iCol);

					dest.push_back(fi);
				}
			}

			return oResult;
		}

		float RateDataStripe(const DataStripe &stripe, Token eOpponent, bool &bCanWin,
			std::vector<uint8_t> &oValidStartOffsets
		)
		{
			assert(eOpponent != Token::None);

			// collect offsets of potential start indexes
			oValidStartOffsets.clear();
			for (size_t iStartOffset = 0; iStartOffset <= stripe.size() - 4; ++iStartOffset)
			{
				if (
					stripe[iStartOffset    ].eType != eOpponent &&
					stripe[iStartOffset + 1].eType != eOpponent &&
					stripe[iStartOffset + 2].eType != eOpponent &&
					stripe[iStartOffset + 3].eType != eOpponent
				)
					oValidStartOffsets.push_back((uint8_t)iStartOffset);
			}

			// rate potential start indexes
			float fResult = 0;
			for (const auto iStartOffset : oValidStartOffsets)
			{
				const auto &field1 = stripe[(size_t)iStartOffset    ];
				const auto &field2 = stripe[(size_t)iStartOffset + 1];
				const auto &field3 = stripe[(size_t)iStartOffset + 2];
				const auto &field4 = stripe[(size_t)iStartOffset + 3];
				
				const uint8_t iMissingTokenCount =
					((field1.iHeightDiff > 0) ? field1.iHeightDiff : 0) +
					((field2.iHeightDiff > 0) ? field2.iHeightDiff : 0) +
					((field3.iHeightDiff > 0) ? field3.iHeightDiff : 0) +
					((field4.iHeightDiff > 0) ? field4.iHeightDiff : 0);

				const float fWinProbability = 1.0f / iMissingTokenCount;
				fResult += fWinProbability;
				if (iMissingTokenCount == 1)
					bCanWin = true;
			}

			return fResult;
		}

		float RateDataStripes(const DataStripes &stripes, Token ePlayer, bool &bCanWin)
		{
			assert(ePlayer != Token::None);

			const auto eOpponent = (ePlayer == Token::Player1) ? Token::Player2 : Token::Player1;
			bCanWin = false;

			std::vector<uint8_t> oTMP;
			oTMP.reserve(4);

			float fResult = 0;
			for (const auto &oStripe : stripes)
			{
				fResult += RateDataStripe(oStripe, eOpponent, bCanWin, oTMP);
			}
			return fResult;
		}

	}



	AI::AI(const Board &board, Token eSelf) :
		m_oBoard(board),
		m_eSelf(eSelf)
	{

	}

	unsigned AI::run()
	{
		constexpr float fNegInfty = -std::numeric_limits<float>::infinity();

		float    fBest = fNegInfty;
		unsigned iBest = BoardWidth;

		for (unsigned iColumn = 0; iColumn < BoardWidth; ++iColumn)
		{
			if (!m_oBoard.hasRoom(iColumn))
				continue;

			Board oBoardCopy = m_oBoard;
			oBoardCopy.dropToken(m_eSelf, iColumn);

			if (oBoardCopy.getWinner() == m_eSelf)
				return iColumn; // current AI wins with this move

			const float fRating = RateBoard(oBoardCopy, m_eSelf);
			if (fRating > fBest || fBest == fNegInfty)
			{
				fBest = fRating;
				iBest = iColumn;
			}
		}

		assert(iBest < BoardWidth);
		return iBest;
	}


	
	float AI::RateBoard(const Board &board, Token eSelf)
	{
		assert(eSelf != Token::None);

		const auto eOpponent = (eSelf == Token::Player1) ? Token::Player2 : Token::Player1;
		const auto oStripes  = GetDataStripes(board);

		bool bCanWin;
		const auto fOwn      = RateDataStripes(oStripes, eSelf,     bCanWin);
		const auto fOpponent = RateDataStripes(oStripes, eOpponent, bCanWin);

		if (bCanWin) // opponent can win with the next move
			return -std::numeric_limits<float>::infinity();
		else
			return fOwn - fOpponent;
	}

}
