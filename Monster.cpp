#include "Monster.h"
#include "GameplayStatics.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"


AMonster::AMonster(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");


	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/monster.bmp", true, 255, 255, 255);
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 30;
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

		if (Direction == 0)
		{
			Y--;
		}
		if (Direction == 1)
		{
			Y++;
		}
		if (Direction == 2)
		{
			X--;
		}
		if (Direction == 3)
		{
			X++;
		}
	}
}
