#pragma once
#include <vector>
#include <string>

class AActor;
class AGameMode;


class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void SetGameMode(AGameMode* NewGameMode);

	template<typename T>
	AActor* SpawnActor()
	{
		AActor* NewActor = new T;
		Actors.push_back(NewActor);
		NewActor->SetWorld(this);

		return NewActor;
	}

	template<typename T>
	AActor* GetActorOfClass()
	{
		for (auto Actor : Actors)
		{
			T* Target = dynamic_cast<T*>(Actor);
			if (Target)
			{
				return Target;
			}
		}

		return nullptr;
	}


	void Load(std::string MapName);




	inline std::vector<class AActor*>& GetActors()
	{
		return Actors;
	}

	void BeginPlay();

	void Tick();

	void Render();

protected:

	std::vector<class AActor*> Actors;

	void Sort();

};


