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

	Load("Data/player.bmp");
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


	SDL_GetTicks64();

	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;
		
		if (KeyCode == SDLK_w)
		{
			Y--;
		}
		if (KeyCode == SDLK_s)
		{
			Y++;
		}
		if (KeyCode == SDLK_a)
		{
			X--;
		}
		if (KeyCode == SDLK_d)
		{
			X++;
		}
		if (KeyCode == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}
	}
}

void APlayer::Load(std::string Filename)
{
	Image = SDL_LoadBMP(Filename.c_str());

	SDL_SetColorKey(Image, SDL_TRUE, SDL_MapRGB(Image->format, 255, 0, 255));

	Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Image);
}

void APlayer::Render()
{
	//AActor::Render();
	__super::Render();
}