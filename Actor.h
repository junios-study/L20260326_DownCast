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

protected:
	int X;
	int Y;
	char Mesh;
};

