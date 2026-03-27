#include "Goal.h"

AGoal::AGoal(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 30;

}

AGoal::~AGoal()
{
}
