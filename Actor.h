#pragma once
#include <string>
//#include "SDL.h"

struct SDL_Surface;
struct SDL_Texture;

class AActor
{
public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();

	//override
	virtual void Tick();

	virtual void Render();

	void SetActorLocation(int NewX, int NewY);

	virtual void Load(std::string Filename);
	
	inline const int GetZOrder() 
	{
		return ZOrder;
	}

protected:
	int X;
	int Y;

	int R;
	int G;
	int B;

	int ZOrder = 0;
	char Mesh;

	SDL_Surface* Image;
	SDL_Texture* Texture;
};

