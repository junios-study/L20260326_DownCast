#include "MyGM.h"
#include "SDL.h"

AMyGM::AMyGM()
{
}

AMyGM::~AMyGM()
{
}

void AMyGM::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		SDL_Log("Game Over");
		bGameOver = true;
	}
}

void AMyGM::GameComplete()
{
	static bool bGameComplte = false;

	if (!bGameComplte)
	{
		SDL_Log("Game Complete");

		bGameComplte = true;
	}
}
