#include "Actor.h"
#include "Engine.h"
#include <iostream>
#include <Windows.h>

AActor::AActor(int InX, int InY, char InMesh) : X(InX), Y(InY)
{
}

AActor::~AActor()
{
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
}

void AActor::SetActorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}