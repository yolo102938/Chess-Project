#pragma once

#include "Piece.h"
#include "Board.h"

class Queen : public Piece
{
public:
	Queen(Board* board, string pos, string type, int color);
	virtual ~Queen();
	virtual bool checkMove(string place);
};