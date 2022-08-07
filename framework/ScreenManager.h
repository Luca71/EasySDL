#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H
#include "InputManager.h";

namespace EasySDL
{
	class ScreenManager
	{
	public:
	
		static ScreenManager* Instance();
		static void Release();
	
		void Update();
		void Render();
	
	private:
	
		ScreenManager();
		~ScreenManager();

		static ScreenManager* sInstance;

		/**
		 * Add screens that you intend to add in the game.
		 * By default only start and play are present.
		 */
		enum SCREENS { start, play };

		InputManager* mInputMgr;

		SCREENS mCurrentScreen;
	};
}


#endif // _SCREENMANAGER_H
