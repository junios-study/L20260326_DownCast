#include "Floor.h"
#include "Engine.h"
#include "ResourceManager.h"


AFloor::AFloor(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	//Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/floor.bmp");
	//Image = TempResource.Image;
	//Texture = TempResource.Texture;
}

AFloor::~AFloor()
{
}
