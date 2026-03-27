#include <iostream>
#include "Engine.h"
#include "World.h"
#include <algorithm>

using namespace std;

void Sort(int* InData, int InLength, int (*Compare)(int A, int B))
{
	for (int FirstIndex = 0; FirstIndex < InLength; ++FirstIndex)
	{
		for (int SecondIndex = 0; SecondIndex < InLength; ++SecondIndex)
		{
			if (Compare(InData[FirstIndex], InData[SecondIndex]) == 1)
			{
				int Temp = InData[FirstIndex];
				InData[FirstIndex] = InData[SecondIndex];
				InData[SecondIndex] = Temp;
			}
		}
	}
}

bool bConnection = true;

int CompleteCallback()
{
	cout << "접속 완료" << endl;

	return 0;
}

void Connect(int (*Complete)())
{
	//callback
	if (bConnection)
	{
		Complete();
	}
}


int Ascending(int A, int B)
{
	if (A < B)
	{
		return 1;
	}
	else if ( A == B)
	{
		return 0;
	}

	return -1;
}

int Decending(int A, int B)
{
	if (A < B)
	{
		return -1;
	}
	else if (A == B)
	{
		return 0;
	}

	return 1;
}

void Test(int A, int B)
{

}

void (*함수포인터이름)(int, int);

//C++
int main()
{
	함수포인터이름 = Test;

	함수포인터이름(1, 2);

	Connect(CompleteCallback);


	//GEngine->GetWorld()->Load("level01.umap");

	//GEngine->Run();

	//delete GEngine;

	//함수 포인터
	//int (*CompareFunction)(void);

	//CompareFunction = Compare2;

	//CompareFunction();

	//cout << Compare << endl;
	//cout << CompareFunction << endl;

	
	int Data[8] = { 9, 1, 3, 5, 7, 8, 2, 10 };
	//search and sort
	//selection and bubble
	//1 9 3 5 4 6 7 8 2 10
	//1 2 9 5 4 6 7 8 3 10

	int Number = 0;


	//일급함수, 함수도 변수에 저장 가능함.
	auto Compare = [Data,Number](int A, int B) -> int {
		return 0;
	};

	Compare(1, 2);


	//람다 함수, 익명 함수, C++ 11 이상
	Sort(Data, 8, [](int A, int B) -> int {

		if (A > B)
		{
			return 1;
		}
		else if (A == B)
		{
			return 0;
		}

		return -1;
		}
	);


	for (int i = 0; i < 8; ++i)
	{
		cout << Data[i] << ",";
	}


	return 0;
}


