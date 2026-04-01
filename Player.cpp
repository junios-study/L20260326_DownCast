#include "Player.h"
#include "Engine.h"

#include <iostream>

APlayer::APlayer(int InX, int InY, char InMesh)  
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 100;

	R = 255;
	G = 0;
	B = 0;
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

	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		
		if (Event.key.keysym.sym == SDLK_w)
		{
			Y--;
		}
		if (Event.key.keysym.sym == SDLK_s)
		{
			Y++;
		}
		if (Event.key.keysym.sym == SDLK_a)
		{
			X--;
		}
		if (Event.key.keysym.sym == SDLK_d)
		{
			X++;
		}
	}
	
}

void APlayer::Render()
{
	//AActor::Render();
	__super::Render();
}