#include "Wall.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"

AWall::AWall(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	SpriteComponent = CreateDefaultSubobject<USpriteComponent>("Sprite");


	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/wall.bmp");
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 50;
}

AWall::~AWall()
{
}
