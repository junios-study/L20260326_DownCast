#include "YoudieActor.h"
#include "TextRenderComponent.h"

AYoudieActor::AYoudieActor()
{
	TextRenderComponent->SetText("You Died.");
	X = 200;
	Y = 100;
	TextRenderComponent->ZOrder = 200;
	TextRenderComponent->bIsVisible = false;
}

AYoudieActor::~AYoudieActor()
{
}
