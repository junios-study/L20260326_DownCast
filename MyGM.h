#pragma once
#include "GameMode.h"
class AMyGM : public AGameMode
{
public:
	AMyGM();
	virtual ~AMyGM();

	void GameOver();
	void GameComplete();
};

