#include "Piece.h"

Piece::Piece(Board* board, string pos, int color)
{
	_position = pos;
	_color = color;
	_b = board;
}

Piece::~Piece()
{
}

int Piece::getColor() const
{
	return this->_color;
}

string Piece::getPositionString() const
{
	return this->_position;
}
int Piece::getPositionNumber_Y(string position)
{
	return int(position[3]);
}

int Piece::getPositionNumber_X(string position)
{
	return int(position[2]) - 96;
}
int Piece::getPositionNumber_Y() const
{
	return int(_position[3])-48;
}

int Piece::getPositionNumber_X() const
{
	return int(_position[2]) - 96;
}