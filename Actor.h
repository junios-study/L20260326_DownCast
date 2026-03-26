#pragma once

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void BeginPlay();

	//override
	virtual void Tick();

	virtual void Render();
};

