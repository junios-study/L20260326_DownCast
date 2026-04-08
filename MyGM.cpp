#include "MyGM.h"
#include "SDL.h"
#include "Engine.h"
#include "World.h"
#include "YoudieActor.h"
#include "TextRenderActor.h"
#include "TextRenderComponent.h"

AMyGM::AMyGM()
{
	Name = "MyGM";
}

AMyGM::~AMyGM()
{
}

void AMyGM::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		AYoudieActor* TextActor = dynamic_cast<AYoudieActor*>(GEngine->GetWorld()->GetActorOfClass<AYoudieActor>());
		if (TextActor)
		{
			TextActor->TextRenderComponent->bIsVisible = true;
		}

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
