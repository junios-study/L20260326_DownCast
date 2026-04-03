#include "GameplayStatics.h"
#include "GameMode.h"

UGameplayStatics::UGameplayStatics()
{
}

UGameplayStatics::~UGameplayStatics()
{
}

AGameMode* UGameplayStatics::GetGameMode()
{
	AActor* Actor = GEngine->GetWorld()->GetActorOfClass<AGameMode>();
	return dynamic_cast<AGameMode*>(Actor);
}
