#include "Wall.h"

AWall::AWall(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 1;

	R = 0;
	G = 255;
	B = 0;

	Load("Data/wall.bmp");

}

AWall::~AWall()
{
}
