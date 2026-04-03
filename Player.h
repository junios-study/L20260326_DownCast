#pragma once
#include "Actor.h"
#include <xkeycheck.h>

class USpriteAnimationComponent;
class UCollisionComponent;
class AActor;

class APlayer : public AActor
{
public:
	APlayer(int InX = 1, int InY = 1, char InMesh = 'P');
	virtual ~APlayer();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	virtual void ReceiveHit(AActor* Other) override;

	void ProcessBeginOverlap(AActor* OtherActor);

	USpriteAnimationComponent* SpriteAnimationComponent;

	UCollisionComponent* CollisionComponent;

protected:
	bool PredictMove(int InX, int InY); //Movement Component 만드셈 //난 안한다.


};

