#include "Monster.h"
#include "GameplayStatics.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"


AMonster::AMonster(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/monster.bmp", true, 255, 255, 255);
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 30;
	ExecutionTime = 0.5f;

	CollisionComponent = CreateDefaultSubobject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = false;
	CollisionComponent->bIsGenerateOverlap = true;

	Name = "Monster";
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	__super::Tick();

	ElapsedTime += UGameplayStatics::GetWorldDeltaSeconds();
	if (ElapsedTime >= ExecutionTime)
	{
		ElapsedTime = 0;

		int Direction = rand() % 5;

		if (Direction == 0 && PredictMove(X, Y - 1))
		{
			Y--;
		}
		if (Direction == 1 && PredictMove(X, Y + 1))
		{
			Y++;
		}
		if (Direction == 2 && PredictMove(X - 1, Y))
		{
			X--;
		}
		if (Direction == 3 && PredictMove(X + 1, Y))
		{
			X++;
		}
	}
}
