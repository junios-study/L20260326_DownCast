#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "GameplayStatics.h"
#include "ResourceManager.h"
#include "SpriteAnimationComponent.h"
#include "CollisionComponent.h"
#include "Goal.h"
#include "MyGM.h"
#include "Monster.h"

APlayer::APlayer(int InX, int InY, char InMesh)  
{
	X = InX;
	Y = InY;

	//Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	//Image = TempResource.Image;
	//Texture = TempResource.Texture;

	SpriteAnimationComponent = CreateDefaultSubobject<USpriteAnimationComponent>("Sprite");

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	SpriteAnimationComponent->Image = TempResource.Image;
	SpriteAnimationComponent->Texture = TempResource.Texture;
	SpriteAnimationComponent->ZOrder = 100;
	SpriteAnimationComponent->ExecutionTime = 0.15f;

	CollisionComponent = CreateDefaultSubobject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = true;
	CollisionComponent->bIsGenerateOverlap = true;

	Name = "Player";

}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	__super::BeginPlay();

	OnActorBeginOverlap = [&](AActor* Other) -> void {
		AGoal* Goal = dynamic_cast<AGoal*>(Other);
		if (Goal)
		{
			AMyGM* GM = dynamic_cast<AMyGM*>(UGameplayStatics::GetGameMode());
			if (GM)
			{
				GM->GameComplete();
			}
		}

		AMonster* Monster = dynamic_cast<AMonster*>(Other);
		if (Monster)
		{
			AMyGM* GM = dynamic_cast<AMyGM*>(UGameplayStatics::GetGameMode());
			if (GM)
			{
				GM->GameOver();
			}
		}
	};

	//OnActorBeginOverlap = std::bind(&APlayer::ProcessBeginOverlap, this, std::placeholders::_1);

}

void APlayer::Tick()
{
	__super::Tick();

	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;
		
		if (KeyCode == SDLK_w && PredictMove(X, Y - 1))
		{
			Y--;
			SpriteAnimationComponent->SpriteIndexY = 2;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_s && PredictMove(X, Y + 1))
		{
			Y++;
			SpriteAnimationComponent->SpriteIndexY = 3;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_a && PredictMove(X - 1, Y))
		{
			X--;
			SpriteAnimationComponent->SpriteIndexY = 0;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_d && PredictMove(X + 1, Y))
		{
			X++;
			SpriteAnimationComponent->SpriteIndexY = 1;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_ESCAPE)
		{ 
			GEngine->Stop();
		}
	}
}

void APlayer::ReceiveHit(AActor* Other)
{

}

void APlayer::ProcessBeginOverlap(AActor* OtherActor)
{
	SDL_Log("°ãÄ§ ");
}


