#pragma once
#include "Board.h"

class Board;

class Piece
{
protected:
	int _color;
	string _position;
	Board* _b;

public:
	Piece(Board* board, string pos, int color);
	~Piece();
	int getColor() const;
	string getPositionString() const;
	int getPositionNumber_X() const;
	int getPositionNumber_Y() const;
	virtual bool checkMove(string place) = 0;
};