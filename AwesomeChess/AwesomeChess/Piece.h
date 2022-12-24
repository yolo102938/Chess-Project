#pragma once
#include "Board.h"

class Board;

class Piece
{
protected:
	int color;
	string position;
	Board* b;

public:
	Piece(string pos, int color);
	~Piece();
	int getColor() const;
	string getPosition() const;
	virtual bool checkMove(string place) = 0;
};