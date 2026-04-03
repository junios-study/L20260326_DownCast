#pragma once
#include "Component.h"
#include "RenderableComponent.h"
#include "SDL.h"

class USpriteComponent : public UComponent, IRenderableComponent
{
public:
	USpriteComponent();
	~USpriteComponent();

	//UComponent의 구현, Abstract Class, 
	virtual void BeginPlay() override;

	virtual void Tick() override;

	//IRenderableComponent를 구현, Interface라는 구현(C++문법이 없음, Blueprint, C#, java)
	//UE에는 있음
	virtual void Render() override;

	int ZOrder = 0;

	int X = 0;
	int Y = 0;

	SDL_Surface* Image;
	SDL_Texture* Texture;
};

