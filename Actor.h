#pragma once
#include <string>
#include <vector>	


struct SDL_Surface;
struct SDL_Texture;

class UComponent;

class AActor
{
public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();

	//override
	virtual void Tick();

	//virtual void Render();

	void SetActorLocation(int NewX, int NewY);
	
	//inline const int GetZOrder() 
	//{
	//	return ZOrder;
	//}


	

protected:
	int X;
	int Y;

	std::vector<UComponent*> Components;

	template<typename T>
	T* CreateDefaultSubobject(std::string ComponentName)
	{
		return new T;
	}

	//int R;
	//int G;
	//int B;

	//int ZOrder = 0;
	//char Mesh;

	//SDL_Surface* Image;
	//SDL_Texture* Texture;
};

