#include "Player.h"

#include <iostream>

APlayer::APlayer()
{
	std::cout << "APlayer 생성자" << std::endl;
}

APlayer::~APlayer()
{
	std::cout << "APlayer 소멸자" << std::endl;
}

void APlayer::BeginPlay()
{
}

void APlayer::Tick()
{
}

void APlayer::Render()
{
}

void APlayer::ApplyDamage(AActor* Other)
{
	std::cout << "공격한다" << std::endl;
}
