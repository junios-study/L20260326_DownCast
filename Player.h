#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer(int InX = 1, int InY = 1, char InMesh = 'P');
	virtual ~APlayer();

	virtual void Tick() override;

protected:
	int SpriteIndexX = 0;
	int SpriteIndexY = 0;

	float ElapsedTime = 0;
	float ExecutionTime = 0.1f;


};

