#include "TextRenderActor.h"
#include "TextRenderComponent.h"

ATextRenderActor::ATextRenderActor()
{
	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
}

ATextRenderActor::~ATextRenderActor()
{

}
