#include "ScreenManager.h"

namespace EasySDL
{
	ScreenManager* ScreenManager::sInstance = nullptr;

	ScreenManager* ScreenManager::Instance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new ScreenManager();
		}
		return sInstance;
	}

	void ScreenManager::Release()
	{
		delete sInstance;
		sInstance = nullptr;
	}

	ScreenManager::ScreenManager()
	{
		mInputMgr = InputManager::Instance();

		// For this game only
		// Example: mBackgroundStars = BackgroundStars::Instance();

		mCurrentScreen = start;
	}

	ScreenManager::~ScreenManager()
	{
		mInputMgr = nullptr;

		// For this game only
		// Example: BackgroundStars::Release();
		// Example: mBackgroundStars = nullptr;

	}

	void ScreenManager::Update()
	{

		switch (mCurrentScreen)
		{
		case start:
	
			if (mInputMgr->KeyPressed(SDL_SCANCODE_RETURN))
			{
				mCurrentScreen = play;
			}
			break;

		case play:
			if (mInputMgr->KeyPressed(SDL_SCANCODE_ESCAPE))
			{
				mCurrentScreen = start;
			}
			break;
		}
	}

	void ScreenManager::Render()
	{
		switch (mCurrentScreen)
		{
		case start:
			
			break;

		case play:
			
			break;
		}
	}
}
