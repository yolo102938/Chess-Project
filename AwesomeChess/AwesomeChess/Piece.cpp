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
string Piece::getType() const
{
	return this->type;
}
void Piece::setPosition(string pos) {
	this->_position = pos;
}
int Piece::getPositionNumber_Y(string position)
{
	return int(position[1])-48;
}

int Piece::getPositionNumber_X(string position)
{
	return int(position[0]) - 96;
}
int Piece::getPositionNumber_Y() const
{
	return int(_position[1])-48;
}

int Piece::getPositionNumber_X() const
{
	return int(_position[0]) - 96;
}