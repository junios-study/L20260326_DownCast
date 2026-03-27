#include "Player.h"
#include "Engine.h"

#include <iostream>

APlayer::APlayer(int InX, int InY, char InMesh)  
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 100;
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	__super::BeginPlay();

}

void APlayer::Tick()
{
	__super::Tick();

	if (UEngine::KeyCode == 'w')
	{
		Y--;
	}
	if (UEngine::KeyCode == 's')
	{
		Y++;
	}
	if (UEngine::KeyCode == 'a')
	{
		X--;
	}
	if (UEngine::KeyCode == 'd')
	{
		X++;
	}

	UEngine::KeyCode = 0;
}

void APlayer::Render()
{
	//AActor::Render();
	__super::Render();
}