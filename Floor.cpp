#include "Floor.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"


AFloor::AFloor(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/floor.bmp");
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 1;
}

AFloor::~AFloor()
{
}
