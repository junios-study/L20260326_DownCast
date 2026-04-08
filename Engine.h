#pragma once

#include <vector>
#include <Windows.h>
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")
#pragma comment(lib, "SDL2_ttf")
#pragma comment(lib, "SDL2_mixer")

class AActor;
class UWorld;
class UResourceManager;


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

	void Stop();


	inline UWorld* GetWorld()
	{
		return World;
	}

	//Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Render(int InX, int InY, int R, int G, int B);
	void Render(int InX, int InY, SDL_Texture* InTexture);

	void Flip();
	void TermBuffer();

	inline const SDL_Event& GetEvent()
	{
		return MyEvent;
	}

	inline float GetDeltaSeconds() const
	{
		return DeltaSeconds;
	}

	inline SDL_Renderer* GetRenderer() const
	{
		return MyRenderer;
	}

	inline SDL_Window* GetWindow() const
	{
		return MyWindow;
	}

	inline UResourceManager* GetResourceManager() const
	{
		return ResourceManager;
	}

	TTF_Font* Font;

protected:
	void Input();
	void Tick();
	void Render();


	class UWorld* World;

	int bIsRunning : 1;

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

	float DeltaSeconds;

	UResourceManager* ResourceManager;
};


#define GEngine			UEngine::GetInstance()