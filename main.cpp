#include <iostream>
#include "Engine.h"
#include "World.h"

#include <random>

#include "SDL.h"
//사용할 라이브러리 복사
//include 경로 추가
//lib 경로 추가
//library 파일 등록 

//사용할 라이브러리 파일 추가
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")


using namespace std;


int SDL_main(int argc, char* argv[])
{
	//rand 좀더 좋은 임의를 선택하기 위해서
	std::random_device RandomDevice;
	std::mt19937 RandomGenerator(RandomDevice());

	std::uniform_int_distribution<int> DistX(0, 640);
	std::uniform_int_distribution<int> DistY(0, 480);

	std::uniform_int_distribution<int> DistR(0, 255);
	std::uniform_int_distribution<int> DistG(0, 255);
	std::uniform_int_distribution<int> DistB(0, 255);
	std::uniform_int_distribution<int> DistA(0, 255);





	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow = SDL_CreateWindow("Hello", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);


	//GPU, 붓
	SDL_Renderer* MyRender = SDL_CreateRenderer(MyWindow, -1, 0);

	while (true)
	{ 
		SDL_Event MyEvent;
		SDL_PollEvent(&MyEvent);

		if (MyEvent.type == SDL_QUIT)
		{
			break;
		}

		//CPU하는건 GPU가 할일을 적는거야. 많이 많이 많이
		//GPU 한테 보낼 명령어 모음
		SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
		SDL_RenderClear(MyRender);

		//어떻게 그릴지 명령어 GPU
		//빨간색 붓 고르고
		 

		SDL_SetRenderDrawColor(MyRender, 255, 0, 0, 0);

		int Radius = 200;
		int CenterX = 500;
		int CenterY = 500;
		int Size = 15;

		for (int Theta = 0; Theta <= 360; Theta += Size)
		{
			float Radian1 = (float)Theta * 3.141592f / 180.0f;
			float Radian2 = (float)(Theta + Size) * 3.141592f / 180.0f;
			int X1 = Radius * SDL_cos(Radian1) + CenterX;
			int Y1 = Radius * SDL_sin(Radian1) + CenterY;
			int X2 = Radius * SDL_cos(Radian2) + CenterX;
			int Y2 = Radius * SDL_sin(Radian2) + CenterY;
			//SDL_RenderDrawPoint(MyRender, X, Y);
			SDL_RenderDrawLine(MyRender, X1, Y1, X2, Y2);
		}



		//그려CPU -> GPU
		SDL_RenderPresent(MyRender);


	}

	SDL_DestroyRenderer(MyRender);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}

//int main()
//{
//	GEngine->GetWorld()->Load("level01.umap");
//
//	GEngine->Run();
//
//	delete GEngine;
//
//	return 0;
//}
//

