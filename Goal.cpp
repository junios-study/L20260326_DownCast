#include "Goal.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"


AGoal::AGoal(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/goal.bmp", true, 255, 255, 255);
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 10;
}

AGoal::~AGoal()
{
}
