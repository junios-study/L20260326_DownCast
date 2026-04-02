#include "Floor.h"

AFloor::AFloor(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 0;

	R = 0;
	G = 0;
	B = 0;

	Load("Data/floor.bmp");
}

AFloor::~AFloor()
{
}
