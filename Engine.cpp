#include "Engine.h"
#include <conio.h>
#include "Actor.h"
#include "World.h"

UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	bIsRunning = true;

	World = new UWorld();
}

void UEngine::Term()
{
	delete World;
	World = nullptr;
}


void UEngine::Run()
{
	while (bIsRunning)
	{
		//Input();
		Tick();
		Render();
	}
}


void UEngine::Input()
{
	int KeyCode = _getch();
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}
