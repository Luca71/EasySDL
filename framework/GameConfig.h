#ifndef _GAMECONFIG_H
#define _GAMECONFIG_H
#include <string>


namespace EasySDL
{
	#define COLOR_RED		255, 0, 0, 255
	#define COLOR_GREEN		0, 255, 0, 255
	#define COLOR_BLUE		0, 0, 255, 255
	#define COLOR_BLACK		0, 0, 0, 255
	#define COLOR_WHITE		255, 255, 255, 255

	class GameConfig
	{
		
	public:
	
		static GameConfig* Instance();
		static void Release();
	
		const int winWidth = 800;
		const int winHeight = 600;
		const std::string winTitle = "EASY SDL";
		const int mainFontSize = 30;
		const bool isFullScreen = false;

		// Add more config params here
	
	private:
	
		GameConfig();
		~GameConfig();
		static GameConfig* sInstance;
	};
}

#endif // _GAMECONFIG_H
