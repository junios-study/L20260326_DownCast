#include "Player.h"

#include <iostream>

APlayer::APlayer(int InX, int InY, char InMesh)  
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
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
}

void APlayer::Render()
{
	//AActor::Render();
	__super::Render();
}