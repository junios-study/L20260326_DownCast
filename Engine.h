#pragma once

#include <vector>

class AActor;


class UEngine
{
public:
	UEngine();
	~UEngine();

	void Init();
	void Term();

	void Run();

	template<typename T>
	void SpawnActor(const AActor* NewActor);

	std::vector<AActor*> GetAllActorOfTag();


protected:
	void Input();
	void Tick();
	void Render();

	std::vector<AActor*> Actors;
};

