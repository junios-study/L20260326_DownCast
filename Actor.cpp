#include "Actor.h"
#include "Engine.h"
#include <iostream>
#include <Windows.h>

AActor::AActor(int InX, int InY, char InMesh) : X(InX), Y(InY), Mesh(InMesh)
{
	R = 0;
	G = 0;
	B = 0;
}

AActor::~AActor()
{
	SDL_FreeSurface(Image);
	SDL_DestroyTexture(Texture);
}

void AActor::BeginPlay()
{

}

void AActor::Tick()
{

}

void AActor::Render()
{
//	GEngine->Render(X, Y, Mesh);
	//GEngine->Render(X, Y, R, G, B);
	GEngine->Render(X, Y, Texture);
}

void AActor::SetActorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}


void AActor::Load(std::string Filename)
{
	Image = SDL_LoadBMP(Filename.c_str());

	Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Image);
}

