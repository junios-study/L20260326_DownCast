#include "Wall.h"
#include "Engine.h"
#include "ResourceManager.h"

AWall::AWall(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	//Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/wall.bmp");
	//Image = TempResource.Image;
	//Texture = TempResource.Texture;
}

AWall::~AWall()
{
}
