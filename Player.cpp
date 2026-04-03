#include "Player.h"
#include "Engine.h"
#include "GameplayStatics.h"
#include "ResourceManager.h"

APlayer::APlayer(int InX, int InY, char InMesh)  
{
	X = InX;
	Y = InY;

	//Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	//Image = TempResource.Image;
	//Texture = TempResource.Texture;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	__super::Tick();

	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;
		
		if (KeyCode == SDLK_w)
		{
			Y--;
			SpriteIndexY = 2;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_s)
		{
			Y++;
			SpriteIndexY = 3;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_a)
		{
			X--;
			SpriteIndexY = 0;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_d)
		{
			X++;
			SpriteIndexY = 1;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_ESCAPE)
		{ 
			GEngine->Stop();
		}
	}

	ElapsedTime += UGameplayStatics::GetWorldDeltaSeconds();
	if (ElapsedTime >= ExecutionTime)
	{
		SpriteIndexX++;
		SpriteIndexX = SpriteIndexX % 5;
		ElapsedTime = 0;
	}
}

//void APlayer::Render()
//{
//	int TileSize = 30;
//	int SpriteSizeX = Image->w / 5;
//	int SpriteSizeY = Image->h / 5;
//
//	//애니메이션 되게 해줘.
//	SDL_Rect SourceRect = { SpriteIndexX * SpriteSizeX, SpriteIndexY * SpriteSizeY, SpriteSizeX, SpriteSizeY };
//	SDL_Rect DestinationRect = { X * TileSize, Y * TileSize, TileSize, TileSize };
//	SDL_RenderCopy(GEngine->GetRenderer(), Texture, &SourceRect, &DestinationRect);
//}