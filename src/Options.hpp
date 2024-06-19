#ifndef ROBINLE_CONNECTFOUR_OPTIONS
#define ROBINLE_CONNECTFOUR_OPTIONS





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


	private: // variables

		bool     m_bShowHelp         = false;
		unsigned m_iHumanPlayerCount = 1;
		bool     m_bPlayer1Starts    = true;

	};

}





#endif // ROBINLE_CONNECTFOUR_OPTIONS