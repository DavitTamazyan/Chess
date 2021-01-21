#include "Bishop.h"
#include <iostream>

#define WHITEBISHOPIMAGE L'B'// 	L'\u2657' 
#define BLACKBISHOPIMAGE L'B'//	L'\u2657'

Bishop::Bishop(FigureColor color, int index) : IChessFigure(color, index)
{
	if (color == FigureColor::WHITE) {
		m_figureImage = WHITEBISHOPIMAGE;
	}
	else
	{
		m_figureImage = BLACKBISHOPIMAGE;
	}
	m_value = 3;
	SetStartPosition();
}

bool Bishop::IsValidMove(int number, int letter, IChessFigure*** table)
{
	if (IsValid(number, letter, table))
	{
		if (table[number][letter] == nullptr)
		{
			Move(number, letter, table);
			return true;
		}
		else if (m_color != table[number][letter]->m_color)
		{
			Eat(number, letter, table);
			return true;

		}
	}
	return false;
}

bool Bishop::IsValid(int number, int letter, IChessFigure*** table)
{
	int numberDiff = m_number - number;
	int letterDiff = m_letter - letter;
	int numberDir = (m_number < number) ? 1 : -1;
	int letterDir = (m_letter < letter) ? 1 : -1;


	if (abs(numberDiff) == abs(letterDiff)) {
		for (int i = m_number + numberDir, j = m_letter + letterDir; i != number; i += numberDir, j += letterDir)
		{
			if (table[i][j] != nullptr) {
				return false;
			}
		
		}
		return true;
	}
	return false;
}

void Bishop::Move(int number, int letter, IChessFigure*** table) {
	IChessFigure* tmp = table[m_number][m_letter];
	table[m_number][m_letter] = table[number][letter];
	table[number][letter] = tmp;
	m_number = number;
	m_letter = letter;
}

void Bishop::Eat(int number, int letter, IChessFigure*** table) {
	table[number][letter]->m_active = false;
	table[number][letter] = table[m_number][m_letter];
	table[m_number][m_letter] = nullptr;
	m_number = number;
	m_letter = letter;
}
void Bishop::SetStartPosition()
{
	if (m_color == FigureColor::WHITE)
	{
		m_number = 0;
		m_letter = (m_index == 1) ? 2 : 5;
		m_1DPlace = m_letter - 1;
	}
	else
	{
		m_number = 7;
		m_letter = (m_index == 1) ? 2 : 5;
		m_1DPlace = m_letter + 55;
	}

}

void Bishop::PrintPeaceImage()
{
	if (m_color == FigureColor::WHITE)
	{
		std::wcout << "\033[40m" << m_figureImage << "\033[0m";
	}
	else
	{
		std::wcout << "\033[32m" << m_figureImage << "\033[0m";
	}
}