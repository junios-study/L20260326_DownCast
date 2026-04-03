#include "Actor.h"
#include "Engine.h"
#include <iostream>
#include <Windows.h>
#include "Component.h"

AActor::AActor(int InX, int InY, char InMesh) : X(InX), Y(InY)
{
}

AActor::~AActor()
{
	for (auto Component : Components)
	{
		delete Component;
	}

	Components.clear();
}

void AActor::BeginPlay()
{
	for (auto Component : Components)
	{
		Component->BeginPlay();
	}
}

void AActor::Tick()
{
	for (auto Component : Components)
	{
		Component->Tick();
	}
}

void AActor::SetActorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}

void AActor::ReceiveHit(AActor* Other)
{
}


UWorld* AActor::GetWorld()
{
	return World;
}

