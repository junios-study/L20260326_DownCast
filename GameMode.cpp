#include "GameMode.h"
#include "Player.h"
#include "Goal.h"
#include "Monster.h"
#include "Engine.h"
#include "World.h"

AGameMode::AGameMode()
{
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	__super::Tick();

	APlayer* Player = dynamic_cast<APlayer*>(GEngine->GetWorld()->GetActorOfClass<APlayer>());
	AMonster* Monster = dynamic_cast<AMonster*>(GEngine->GetWorld()->GetActorOfClass<AMonster>());
	AGoal* Goal = dynamic_cast<AGoal*>(GEngine->GetWorld()->GetActorOfClass<AGoal>());

	if (Player && Goal)
	{
		if (Player->GetX() == Goal->GetX() && Player->GetY() == Goal->GetY())
		{
			SDL_Log("Complete");
			GEngine->Stop();
		}
	}

	if (Player && Monster)
	{
		if (Player->GetX() == Monster->GetX() && Player->GetY() == Monster->GetY())
		{
			SDL_Log("You Die.");
			GEngine->Stop();
		}
	}

}
