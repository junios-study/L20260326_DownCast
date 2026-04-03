#include "SpriteComponent.h"
#include "Engine.h"

USpriteComponent::USpriteComponent()
{
}

USpriteComponent::~USpriteComponent()
{
}

void USpriteComponent::BeginPlay()
{
}

void USpriteComponent::Tick()
{
}

void USpriteComponent::Render()
{
	int TileSize = 30;
	SDL_Rect DestinationRect = { X * TileSize, Y * TileSize, TileSize, TileSize };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, nullptr, &DestinationRect);
}
