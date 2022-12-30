#pragma once
#include "Board.h"

class Board;

class Piece
{
protected:
	int _color;
	string type;
	string _position;
	Board* _b;

public:
	Piece(Board* board, string pos, int color);
	~Piece();
	void setPosition(string pos);
	int getColor() const;
	string getType() const;
	string getPositionString() const;
	int getPositionNumber_X() const;
	int getPositionNumber_Y() const;
	virtual bool checkMove(string place) = 0;
	static int getPositionNumber_X(string position);
	static int getPositionNumber_Y(string position);
};