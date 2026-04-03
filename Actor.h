#pragma once
#include <string>
#include <vector>	
#include <functional>

using FActorBeginOverlapSignature = std::function<void(class AActor* OtherActor)>;

struct SDL_Surface;
struct SDL_Texture;

class UComponent;


class AActor
{
public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();

	virtual void Tick();

	void SetActorLocation(int NewX, int NewY);
	
	std::vector<UComponent*> Components;

	inline int GetX() const
	{
		return X;
	}

	inline int GetY() const
	{
		return Y;
	}

	FActorBeginOverlapSignature OnActorBeginOverlap;

	virtual void ReceiveHit(class AActor* Other);

protected:
	int X;
	int Y;

	template<typename T>
	T* CreateDefaultSubobject(std::string ComponentName)
	{
		T* Temp = new T;
		Temp->Owner = this;
		Components.push_back(Temp);

		return Temp; 
	}

	//int R;
	//int G;
	//int B;

	//int ZOrder = 0;
	//char Mesh;

	//SDL_Surface* Image;
	//SDL_Texture* Texture;
};

