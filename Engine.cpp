#include "Engine.h"
#include "Actor.h"

UEngine::UEngine()
{
}

UEngine::~UEngine()
{
}

void UEngine::Init()
{
}

void UEngine::Term()
{
}


void UEngine::Run()
{
}


void UEngine::Input()
{
}

void UEngine::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UEngine::Render()
{
}
