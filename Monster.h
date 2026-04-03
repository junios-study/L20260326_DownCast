#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster(int InX = 0, int InY = 0, char InMesh = 'M');
	virtual ~AMonster();

	virtual void Tick() override;

protected:
	float ElapsedTime = 0;
	float ExecutionTime = 0.1f;

	class USpriteComponent* SpriteComponent;

};

