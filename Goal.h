#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal(int InX = 0, int InY = 0, char InMesh = 'G');
	virtual ~AGoal();
};

