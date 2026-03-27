#include "Floor.h"

AFloor::AFloor(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 0;
}

AFloor::~AFloor()
{
}
