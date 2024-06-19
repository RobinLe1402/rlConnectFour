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

		
		static Options *GetInstance() { return s_pInstance; }
		static bool NoColor() { return s_pInstance && s_pInstance->m_bNoColor; }


	private: // variables

		bool     m_bNoColor          = false;
		bool     m_bShowHelp         = false;
		unsigned m_iHumanPlayerCount = 1;
		bool     m_bPlayer1Starts    = true;
		
		std::string m_sPlayerNames[2] = {};


	private: // static variables

		static Options *s_pInstance;

	};

}





#endif // ROBINLE_CONNECTFOUR_OPTIONS