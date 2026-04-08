#pragma once

//interface, c++ interface ¾øÀ½
//abstract class, pure virtual function
class IRenderableComponent
{
public:
	virtual void Render() = 0;

	int ZOrder = 0;

	int bIsVisible : 1 ;
};

