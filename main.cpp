#include <iostream>
#include "Player.h"

using namespace std;

int main()
{
	AActor* Monster = new APlayer();
	AActor* MyActor = new AActor();

	//Down Casting, 동적 변환, 
	APlayer* Player = dynamic_cast<APlayer*>(MyActor);

	if (Player)
	{
		Player->ApplyDamage(Monster);
	}
	
	//모든 액터를 어찌한다.

	delete MyActor;

	return 0;
}