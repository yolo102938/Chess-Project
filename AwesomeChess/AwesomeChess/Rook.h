#pragma once

#include "Board.h"
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(Board* board, string pos, string type, int color);
	virtual ~Rook();
	virtual bool checkMove(string place);
};