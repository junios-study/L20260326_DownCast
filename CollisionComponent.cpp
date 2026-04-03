#include "CollisionComponent.h"
#include "Engine.h"
#include "World.h"
#include "Actor.h"

UCollisionComponent::UCollisionComponent() : bIsGenerateHit(false), bIsGenerateOverlap(false)
{
}

UCollisionComponent::~UCollisionComponent()
{
}

void UCollisionComponent::BeginPlay()
{
}

void UCollisionComponent::Tick()
{
	for (auto Other : Owner->GetWorld()->GetActors())
	{
		if (Other == this->Owner) //자기 비교 할필요가 없음
		{
			continue;
		}

		for (auto OtherComponent : Other->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
			if (OtherCollision)
			{
				if (OtherCollision->bIsGenerateHit &&
					Owner->GetX() == Other->GetX() && Owner->GetY() == Other->GetY())
				{
					Other->ReceiveHit(Owner);
					Owner->ReceiveHit(Other);
				}

				if (OtherCollision->bIsGenerateOverlap &&
					Owner->GetX() == Other->GetX() && Owner->GetY() == Other->GetY())
				{
					if (Owner->OnActorBeginOverlap)
					{
						Owner->OnActorBeginOverlap(Other);
					}
					if (Other->OnActorBeginOverlap)
					{
						Other->OnActorBeginOverlap(Owner);
					}
				}
			}
		}
	}
}
