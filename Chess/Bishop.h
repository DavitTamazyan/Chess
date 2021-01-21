#pragma once

#include "IChessFigure.h"

class Bishop : public IChessFigure
{
public:
	Bishop(FigureColor color, int index);

	bool IsValidMove(int number, int letter, IChessFigure*** table);

	bool IsValid(int number, int letter, IChessFigure*** table);

	void SetStartPosition();

	void Move(int number, int letter, IChessFigure*** table);

	void Eat(int number, int letter, IChessFigure*** table);

	void PrintPeaceImage();
};