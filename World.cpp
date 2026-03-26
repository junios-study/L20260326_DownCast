#include "World.h"

#include <fstream>

#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "Wall.h"
#include "Floor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UWorld::Load(std::string MapName)
{
	std::ifstream MapStream(MapName);

	int Y = 0;
	while (!MapStream.eof())
	{
		std::string Line;
		std::getline(MapStream, Line);
		for (int X = 0; X < Line.length(); ++X)
		{
			if (Line[X] == '*')
			{
				SpawnActor<AWall>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == ' ')
			{
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == 'P')
			{
				SpawnActor<APlayer>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == 'M')
			{
				SpawnActor<AMonster>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == 'G')
			{
				SpawnActor<AGoal>()->SetActorLocation(X, Y);
			}
		}
		Y++;
	}


	//파일 읽어서 생성.
	//fopen,
	//ifstream

	//SpawnActor<APlayer>();
	//SpawnActor<AMonster>()->SetActorLocation(4, 5);
	//SpawnActor<AGoal>()->SetActorLocation(8, 8);

	//SpawnActor<AWall>()->SetActorLocation(0, 0);
	//SpawnActor<AWall>()->SetActorLocation(1, 0);
	//SpawnActor<AWall>()->SetActorLocation(2, 0);
	//SpawnActor<AWall>()->SetActorLocation(3, 0);
	//SpawnActor<AWall>()->SetActorLocation(4, 0);
	//SpawnActor<AWall>()->SetActorLocation(5, 0);
	//SpawnActor<AWall>()->SetActorLocation(6, 0);
	//SpawnActor<AWall>()->SetActorLocation(7, 0);
	//SpawnActor<AWall>()->SetActorLocation(8, 0);
	//SpawnActor<AWall>()->SetActorLocation(9, 0);


	//SpawnActor<AFloor>()->SetActorLocation(3, 5);
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

