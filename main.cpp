#include <iostream>
#include "Engine.h"
#include "World.h"

#include "Actor.h"
#include "Player.h"

#include <fstream>

using namespace std;


int main()
{
	UEngine* MyEngine = new UEngine();

	MyEngine->GetWorld()->Load("level01.umap");

	MyEngine->Run();

	delete MyEngine;

	return 0;
}
