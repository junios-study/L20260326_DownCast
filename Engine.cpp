#include "Engine.h"
#include "Actor.h"
#include "World.h"
#include "SDL.h"
#include "ResourceManager.h"

UEngine* UEngine::Instance = nullptr;


UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	MyWindow = SDL_CreateWindow("Hello", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	//MyRender = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_SOFTWARE);
	Mix_Init(MIX_INIT_MP3);
	int Success = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

	TTF_Init();

	Font = TTF_OpenFont("./Data/font.ttf", 32);


	ResourceManager = new UResourceManager();

	bIsRunning = true;

	InitBuffer();

	World = new UWorld();
}

void UEngine::Term()
{
	//리로스 매니저 바꾸면 된다.
	if (Font)
	{
		TTF_CloseFont(Font);
	}

	Mix_CloseAudio();

	TTF_Quit();
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

	delete World;
	TermBuffer();
	World = nullptr;

	delete ResourceManager;
}


void UEngine::Run()
{
	World->BeginPlay();

	Uint64 LastTime;
	while (bIsRunning)
	{
		LastTime = SDL_GetTicks64();

		SDL_PollEvent(&MyEvent);
		Input();
		Tick();
		Render();
		DeltaSeconds = (float)(SDL_GetTicks64() - LastTime) / 1000.0f; // m/s
		//SDL_Log("%f s", DeltaSeconds );
	}
}

void UEngine::Stop()
{
	bIsRunning = false;
}


void UEngine::InitBuffer()
{
	//ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	//CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	//ConsoleCursorInfo.dwSize = 1;
	//ConsoleCursorInfo.bVisible = FALSE;

	//SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	//SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);

}

void UEngine::Clear()
{
	//CPU하는건 GPU가 할일을 적는거야. 많이 많이 많이
	//GPU 한테 보낼 명령어 모음
	SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 255);
	SDL_RenderClear(MyRenderer);

	//Console Clear
	//DWORD DW;
	//FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25, COORD{ 0, 0 }, &DW);
}

void UEngine::Render(int InX, int InY, char InMesh)
{
	//char MeshString[2] = { 0, };
	//MeshString[0] = InMesh;

	//SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{ (SHORT)InX, (SHORT)InY });
	//WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);
}

void UEngine::Render(int InX, int InY, int R, int G, int B)
{
	int TileSize = 30;
	SDL_SetRenderDrawColor(MyRenderer, R, G, B, 255);
	//SDL_RenderDrawPoint(MyRender, InX, InY);
	SDL_Rect MyRect = { InX * TileSize, InY * TileSize, TileSize, TileSize };
	SDL_RenderFillRect(MyRenderer, &MyRect);
}

void UEngine::Render(int InX, int InY, SDL_Texture* InTexture)
{
	int TileSize = 30;

	SDL_Rect MyRect = { InX * TileSize, InY * TileSize, TileSize, TileSize };
	SDL_RenderCopy(MyRenderer, InTexture, nullptr, &MyRect);
}



void UEngine::Flip()
{
	//SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	//ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	//CloseHandle(ScreenBufferHandle[0]);
	//CloseHandle(ScreenBufferHandle[1]);
}

void UEngine::Input()
{
	//if (_kbhit())
	//{
	//	KeyCode = _getch();
	//}
}

void UEngine::Tick()
{
	if (MyEvent.type == SDL_QUIT)
	{
		bIsRunning = false;
	}

	World->Tick();
}

void UEngine::Render()
{
	World->Render();

	//그려CPU -> GPU
	SDL_RenderPresent(MyRenderer);
}
