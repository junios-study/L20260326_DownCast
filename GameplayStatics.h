#pragma once
#include "Engine.h"
#include "World.h"


class AActor;
class AGameMode;

class UGameplayStatics
{
public:
	UGameplayStatics();
	virtual ~UGameplayStatics();

	inline static float GetWorldDeltaSeconds()
	{
		return GEngine->GetDeltaSeconds();
	}

	static AGameMode* GetGameMode();
};

