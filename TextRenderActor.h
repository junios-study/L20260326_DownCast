#pragma once
#include "Actor.h"

class UTextRenderComponent;

class ATextRenderActor :  public AActor
{
public:
	ATextRenderActor();
	virtual ~ATextRenderActor();


	UTextRenderComponent* TextRenderComponent;
};

