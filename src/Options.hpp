#ifndef ROBINLE_CONNECTFOUR_OPTIONS
#define ROBINLE_CONNECTFOUR_OPTIONS





#include <string>



namespace rlConnectFour
{

	class Options
	{
	public: // methods

		Options(int argc, char **argv);

		bool getShowHelp() const { return m_bShowHelp; }
		unsigned getHumanPlayerCount() const { return m_iHumanPlayerCount; }
		bool getPlayer1Starts() const { return m_bPlayer1Starts; }

		void printHelp() const;

		const std::string &getPlayer1Name() const { return m_sPlayerNames[0]; }
		const std::string &getPlayer2Name() const { return m_sPlayerNames[1]; }


	private: // variables

		bool     m_bShowHelp         = false;
		unsigned m_iHumanPlayerCount = 1;
		bool     m_bPlayer1Starts    = true;
		
		std::string m_sPlayerNames[2] = {};

	};

}





#endif // ROBINLE_CONNECTFOUR_OPTIONS