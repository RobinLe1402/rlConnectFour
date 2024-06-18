#ifndef ROBINLE_CONNECTFOUR_CONSOLE
#define ROBINLE_CONNECTFOUR_CONSOLE



namespace Console
{

	enum class Color
	{
		Black,
		Red,
		Green,
		Yellow,
		Blue,
		Magenta,
		Cyan,
		White,
		BrightBlack,
		BrightRed,
		BrightGreen,
		BrightYellow,
		BrightBlue,
		BrightMagenta,
		BrightCyan,
		BrightWhite
	};

	void SetForegroundColor(Color cl);
	void SetBackgroundColor(Color cl);
	void SetColors(Color clForeground, Color clBackground);

	void ResetColors();

}



#endif // ROBINLE_CONNECTFOUR_CONSOLE