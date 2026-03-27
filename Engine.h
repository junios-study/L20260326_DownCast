#pragma once

#include <vector>
#include <Windows.h>

class AActor;
class UWorld;


class UEngine
{
protected:
	UEngine();

	static UEngine* Instance;

public:
	~UEngine();

	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new UEngine();
		}

		return Instance;
	}

	void Init();
	void Term();

	void Run();

	inline UWorld* GetWorld()
	{
		return World;
	}

	static int KeyCode;
	
	//Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Flip();
	void TermBuffer();

protected:
	void Input();
	void Tick();
	void Render();


	class UWorld* World;

	int bIsRunning : 1;

};


#define GEngine			UEngine::GetInstance()