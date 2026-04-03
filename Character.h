#pragma once
#include "Actor.h"

class ACharacter : public AActor
{
public:
	ACharacter();
	virtual ~ACharacter();

protected:
	bool PredictMove(int InX, int InY); //Movement Component 만드셈 //난 안한다.
};

