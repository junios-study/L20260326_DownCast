#pragma once
#include <vector>
#include <string>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	template<typename T>
	AActor* SpawnActor()
	{
		AActor* NewActor = new T;
		Actors.push_back(NewActor);

		return NewActor;
	}

	void Load(std::string MapName);




	inline std::vector<class AActor*>& GetActors()
	{
		return Actors;
	}

	void Tick();

	void Render();

protected:

	std::vector<class AActor*> Actors;

	void Sort();

};


