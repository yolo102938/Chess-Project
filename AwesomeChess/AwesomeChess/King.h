#pragma once
#include "Board.h"
#include "Piece.h"

using std::string;

class Board;

class King : public Piece
{
public:
	King(Board* board, string pos, string type, int color);
	virtual ~King();
	virtual bool checkMove(string place);
};