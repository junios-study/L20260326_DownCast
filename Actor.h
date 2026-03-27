#pragma once

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
	
	inline const int GetZOrder() 
	{
		return ZOrder;
	}

protected:
	int X;
	int Y;
	int ZOrder = 0;
	char Mesh;
};

