#pragma once

#include "Component.h"
#include "RenderableComponent.h"


class UTextRenderComponent : public UComponent, public IRenderableComponent
{
public:
	UTextRenderComponent();
	virtual ~UTextRenderComponent();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	virtual void Render() override;



};

